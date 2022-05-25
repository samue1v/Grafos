
#lembar de adicionar iinicialmente na fila o primeiro
class Heap():
    def __init__(self,vec):
        self.h = vec[:]
        self.l = len(vec)-1
        self.heapMin()

    def heapRem(self):
        r = self.h.pop()
        self.l -=1
        self.heapMin()
        return r
        
    def heapMin(self):
        if self.l>2:
            i = 1
            while i*2<=self.l:
                actual = self.h[i]
                f_son  = self.h[2*i]
                ##
                if 2*i+1<=self.l:
                    s_son = self.h[2*i+1]
                else:
                    s_son = self.h[0]#dumb vertex
                if actual.k < f_son.k or actual.k < s_son.k:
                    if f_son.k > s_son.k:
                        aux = actual
                        actual = f_son
                        f_son = aux
                    else:
                        aux = actual
                        actual = s_son
                        s_son = aux
                i+=1
        else:
            if self.l>1:
                if self.h[1].k< self.h[2].k:
                    aux = self.h[1]
                    self.h[1] = self.h[2]
                    self.h[2] = aux


    
