
#lembar de adicionar iinicialmente na fila o primeiro
class Heap():
    def __init__(self,vec):
        self.h = vec
        self.l = len(vec)
        self.heapMin()

    def heapRem(self):
        r = self.h.pop()
        self.l -=1
        self.heapMin()
        return r
        
    def heapMin(self):
        if self.l>3:
            for i in range(1,int(self.l/3)):
                actual = self.h[i]
                f_son  = self.h[2*i]
                s_son = self.h[2*i+1]
                if actual < f_son or actual < s_son:
                    if f_son > s_son:
                        aux = actual
                        actual = f_son
                        f_son = aux
                    else:
                        aux = actual
                        actual = s_son
                        s_son = aux
        else:
            if self.l>2:
                if self.h[1]< self.h[2]:
                    aux = self.h[1]
                    self.h[1] = self.h[2]
                    self.h[2] = aux



def main():
    q = []
    q.append(-1)
    a=1
    while a >= 0:
        a = int(input("Digite o valor:")) 
        q.append(a)
    h = Heap(q)
    while(h.l>1):
        print(h.heapRem())


if __name__ == "__main__":
    main()
    
    
            