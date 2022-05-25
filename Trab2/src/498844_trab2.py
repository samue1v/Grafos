from collections import deque
#Colocando -1 na criação
class Heap():
    def __init__(self):
        self.h = deque([-1])
        self.l = 0
    
    def heapAdd(self,ele):
        self.h.append(ele)
        self.l+=1
        ele.heap_pos = self.l
        self.sobe(self.l)


    def heapRem(self):
        dumb = self.h.popleft()
        r = self.h.popleft()
        self.h.appendleft(dumb)
        self.l -=1
        if self.l>0:
            ultimo = self.h.pop()
            dumb = self.h.popleft()
            self.h.appendleft(ultimo)
            self.h.appendleft(dumb)
            #ultimo troca para o primeiro
            ultimo.heap_pos = 1#
            self.desce(1)
        return r

    def sobe(self,pos):
        if int(pos/2)>0:
            pai_pos = int(pos/2)
            f = self.h[pai_pos]
            s = self.h[pos]
            if f.k>s.k:
                self.exchange_index(f,s)#
                aux = f
                self.h[pai_pos] = s
                self.h[pos] = f
                self.sobe(pai_pos)

    def desce(self,pos):
        f_son = 2*pos
        s_son = 2*pos+1
        if s_son<= self.l:
            if self.h[pos].k> self.h[s_son].k or self.h[pos].k> self.h[f_son].k:
                if self.h[s_son].k < self.h[f_son].k:
                    aux = self.h[s_son]
                    self.h[s_son] = self.h[pos]
                    self.h[pos] = aux
                    self.exchange_index(self.h[s_son],self.h[pos])#
                    self.desce(s_son)
                else:
                    aux = self.h[f_son]
                    self.h[f_son] = self.h[pos]
                    self.h[pos] = aux
                    self.exchange_index(self.h[f_son],self.h[pos])#
                    self.desce(f_son)
        if f_son<=self.l:
            if self.h[pos].k > self.h[f_son].k:
                    aux = self.h[f_son]
                    self.h[f_son] = self.h[pos]
                    self.h[pos] = aux
                    self.exchange_index(self.h[f_son],self.h[pos])#
                    self.desce(f_son)
        
    def exchange_index(self,v1,v2):
        aux = v1.heap_pos
        v1.heap_pos = v2.heap_pos
        v2.heap_pos = aux

class Vertex():
    def __init__(self,label):
        self.label = label
        self.parent = None
        self.done = False
        self.inq = False
        self.k=float("inf")
        self.heap_pos = -1
        self.neighbours = []


        
class Graph():
    def __init__(self):
        self.vertexVec = []
    def addNeigh(self,v1,v2,w):
        v1.neighbours.append((v2,w))
        v2.neighbours.append((v1,w))
    def addVertex(self,label):
        v = Vertex(label)
        self.vertexVec.append(v)

def parseInput(g):
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
        e = (r.split(" "))
        g.addNeigh(g.vertexVec[int(e[0])] , g.vertexVec[int(e[1])],float(e[2]))

def MSTsum(g,heap):
    peso=0
    while(heap.l>0):
        u = heap.heapRem()
        u.done = True
        peso+=u.k
        for v in u.neighbours:
            vv= v[0]
            vw = v[1]
            if vv.done == False:
                if vw<vv.k:
                    vv.parent = u
                    vv.k=vw
                    if vv.inq == True:
                        heap.sobe(vv.heap_pos)#
                    else:
                        vv.inq = True
                        heap.heapAdd(vv)
    return peso
    
g = Graph()
g.addVertex(-1)
parseInput(g)#crio o vetor de vertices e crio e inicializo a matriz de pesos
heap = Heap()#inicializo o heap
v0 = g.vertexVec[1]
v0.k = 0
heap.heapAdd(v0)
p = MSTsum(g,heap)
print(f"{p:.3f}")
    
