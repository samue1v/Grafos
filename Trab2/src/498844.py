

class Heap():
    def __init__(self,vec):
        self.h = vec
        self.h.insert(0,(0,-1))
        self.minH()

    def heapRem(self):
        r = self.h.pop(1)
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
                
                a = self.h[i]
                f1 = self.h[2*i]
                f2 = self.h[2*i+1]
                if a[1]>f1[1] or a[1]>f2[1]:
                    if f1[1]<f2[1]:
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
            
            if len(self.h)>2 and self.h[1][1]>self.h[2][1]:
                aux = self.h[1][1]
                self.h[1][1] = self.h[2][1]
                self.h[2][1]=aux
            return False
            
                    

class Vertex():
    def __init__(self,label):
        self.label = label
        self.done = False
        self.doneq = False
        self.color = 0
        self.neighbours = []

        
        
class Graph():
    def __init__(self):
        self.__vertexVec = []
        self.__q=[]
    def getQ(self):
        return self.__q
    def addQ(self,e):
        self.__q.append(e)
    def getVertex(self,index):
        return self.__vertexVec[index]
    def addNeigh(self,v1,v2,w):
        v1.neighbours.append((v2,w))
        v2.neighbours.append((v1,w))
    def addVertex(self,pair):
        v = Vertex(pair)
        self.__vertexVec.append(v)
    def vecVertexSize(self):
        return len(self.__vertexVec)


def MSTsum(G):
    pass
    
def parseInput(g):
    e = []
    r=input()
    r=input()
    r=input()
    n=int(r.strip("n="))
    for i in range(1,n+1):
        g.addVertex(i)
        g.addQ([i,float('inf')])
    r=input()
    while True:
        try:
            r = input()
        except:
            break
        e.append(r.split(" "))
        g.addNeigh(g.getVertex(int(e[-1][0])) , g.getVertex(int(e[-1][1])),float(e[-1][2]))





def main():
    g = Graph()
    parseInput(g)
    heap = Heap(g.getQ)
    while(len(heap.h)>1):
        heap.minH()
        print(heap.h)
        heap.h.pop(1)
    print(heap.h)
    #color = 0
    #parseInput(g)
    #for i in range(0,g.vecVertexSize()):
    #    v = g.getVertex(i)
    #    if v.color == 0:
    #        color+=1
    #        BFS(g,v,color)
    #showResult(g)




        

            

if __name__ == "__main__":
    main()