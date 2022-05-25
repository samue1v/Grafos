from collections import deque
from dbm import dumb
#Colocando -1 na criação
class Heap():
    def __init__(self):
        self.h = deque([-1])
        self.l = 0
    
    def heapAdd(self,ele):
        self.h.append(ele)
        self.l+=1
        #ele.pos_heap = self.l
        self.sobe(self.l)


    def heapRem(self):
        dumb = self.h.popleft()
        r = self.h.popleft()
        self.h.appendleft(dumb)
        self.l -=1
        if self.l>0:
            self.rearangeHeap(1)
        return r

    def sobe(self,pos):
        if int(pos/2)>0:
            pai_pos = int(pos/2)
            f = self.h[pai_pos]
            s = self.h[pos]
            if f.k>s.k:
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
                    self.desce(s_son)
                else:
                    aux = self.h[f_son]
                    self.h[f_son] = self.h[pos]
                    self.h[pos] = aux
                    self.desce(f_son)
        if f_son<=self.l:
            if self.h[pos].k > self.h[f_son].k:
                    aux = self.h[f_son]
                    self.h[f_son] = self.h[pos]
                    self.h[pos] = aux
                    self.desce(f_son)
        
          
    def rearangeHeap(self,pos):
        ultimo = self.h.pop()
        dumb = self.h.popleft()
        self.h.appendleft(ultimo)
        self.h.appendleft(dumb)
        self.desce(pos)

