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
    def getVertex(self,index):
        return self.__vertexVec[index]
    def addNeigh(self,v1,v2):
        v1.neighbours.append(v2)
        v2.neighbours.append(v1)
    def addVertex(self,label):
        v = Vertex(label)
        self.__vertexVec.append(v)
    def vecVertexSize(self):
        return len(self.__vertexVec)

def main():
    g = Graph()
    color = 0
    parseInput(g)
    for i in range(0,g.vecVertexSize()):
        v = g.getVertex(i)
        if v.color == 0:
            color+=1
            BFS(g,v,color)
    showResult(g)

def BFS(g,v,color):
    q = []
    q.append(v)
    v.doneq = True
    while len(q)>0:
        v1 = q[0]
        v1.color=color
        q.pop(0)
        for i in v1.neighbours:
            if i.color == 0 and i.doneq == False:
                i.doneq = True
                q.append(i)

def parseInput(g):
    e = []
    r=input()
    r=input()
    r=input()
    n=int(r.strip("n="))
    for i in range(1,n+1):
        g.addVertex(i)
    r=input()
    while True:
        try:
            r = input()
        except:
            break
        e.append(r.split(" "))
        g.addNeigh(g.getVertex(int(e[-1][0])-1) , g.getVertex(int(e[-1][1])-1))
        
def showResult(g):
    size = g.vecVertexSize()
    for i in range(0,size):
        cont = 0
        v=g.getVertex(i)
        if v.done == False:
            color = v.color
            for j in range(0,size):
                v1=g.getVertex(j)
                if v1.done == False and v1.color == color:
                    if cont !=0:
                        print(" ",end='')
                    print(v1.label,end='')
                    v1.done = True
                    cont+=1
            print("")
            

if __name__ == "__main__":
    main()