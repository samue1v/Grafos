

class Heap():
    def __init__(self,vec):
        self.h = vec[:]
        self.h.insert(0,'ini')

    def heapRem(self):
        r = self.h.pop(1)
        r.inq = False
        self.minH()
        return r
        
    def minH(self):
        while True:
            if(self.heapfy()):
                continue
            break
    
    def heapfy(self):
        
        if len(self.h)>3:
            i=1
            while True:
                
                a = self.h[i].k
                f1 = self.h[2*i].k
                f2 = self.h[2*i+1].k
                if a>f1 or a>f2:
                    if f1<f2:
                        self.h[2*i] = a
                        self.h[i] = f1
                    else:
                        self.h[2*i+1] = a 
                        self.h[i] = f2
                    return True
                i+=1
                if i*2+1>=len(self.h):
                    return False
        else:
            
            if len(self.h)>2 and self.h[1].k>self.h[2].k:
                aux = self.h[1]
                self.h[1] = self.h[2]
                self.h[2]=aux
            return False
            
###############################################################                   

class Vertex():
    def __init__(self,label):
        self.label = label
        self.parent = None
        self.inq = True
        self.k=float('inf')
        self.color = 0
        self.neighbours = []

        
        
class Graph():
    def __init__(self):
        self.__vertexVec = []
    def getvertexVec(self):
        return self.__vertexVec
    def getVertex(self,index):
        return self.__vertexVec[index]
    def addNeigh(self,v1,v2,w):
        v1.neighbours.append(v2)
        v2.neighbours.append(v1)
        self.__w[v1.label-1][v2.label-1] = w
        self.__w[v2.label-1][v1.label-1] = w
    def addVertex(self,label):
        v = Vertex(label)
        self.__vertexVec.append(v)
    def vecVertexSize(self):
        return len(self.__vertexVec)
    def createW(self,n):
        self.__w = [[float('inf') for _ in range(n)] for _ in range(n)]
    def getW(self,v1,v2):
        return self.__w[v1.label-1][v2.label-1]


def parseInput(g):
    e = []
    r=input()
    r=input()
    r=input()
    n=int(r.strip("n="))
    g.createW(n)
    for i in range(1,n+1):
        g.addVertex(i)
    r=input()
    while True:
        r = input()
        if not r:
            break
        e = (r.split(" "))
        g.addNeigh(g.getVertex(int(e[0])-1) , g.getVertex(int(e[1])-1),float(e[2]))



def MSTsum(g,heap):
    peso=0
    while(len(heap.h)>1):
        u = heap.heapRem()
        peso+=u.k
        for v in u.neighbours:
            w = g.getW(u,v)
            if v.inq == True and w<v.k:
                v.parent = u
                v.k=w
    return peso
    


def main():
    g = Graph()
    parseInput(g)#crio o vetor de vertices e crio e inicializo a matriz de pesos
    heap = Heap(g.getvertexVec())#inicializo o heap
    v0 = g.getVertex(0)
    v0.k = 0
    heap.minH()
    p = MSTsum(g,heap)
    print(f"{p:.3f}")
    






        

            

if __name__ == "__main__":
    main()