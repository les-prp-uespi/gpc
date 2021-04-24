from collections import defaultdict
import string
class Graph:
 
    def __init__(self):
        self.graph = defaultdict(list)
        self.queue = []
        self.alfabeto = list(string.ascii_lowercase)
 
    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)
 
    def BFS(self, s, indice):
    
        self.queue.append(self.alfabeto[indice])
        self.visited[indice] = True
        valores = []
        while self.queue:

            s = self.queue.pop(0)
            valores.append(s)
 
        
            for i in self.graph[s]:
                indice = self.alfabeto.index(i)
                if self.visited[indice] == False:
                    self.queue.append(i)
                    self.visited[indice] = True
        valores = sorted(valores)
        for j in valores:
            print(str(j) + ',',end="")



    def componentesConexos(self, V):
        self.visited = [False] * int(V)
        compontent = 0
        i = 0
        for j in range(int(V)):
            if self.visited[i] == False:
                compontent += 1
                self.BFS(self.alfabeto[i], i)
                print('')
            i += 1 
        print(str(compontent) + ' connected components\n')



while True:
  try:
    contador = 1
    n = int(input())
    while n:
        alfabeto = list(string.ascii_lowercase)
        v, e = input().split(' ')
        g = Graph()
        for i in range(0, int(e)):
            vi , vj = input().split(' ')
            g.addEdge(vi, vj)
        for l in range(0, int(v)):
            if(alfabeto[l] not in g.graph):
                g.graph[alfabeto[l]] = []
        n -= 1
        print('Case #'+str(contador)+':')
        contador += 1
        g.componentesConexos(v)
  except EOFError:
      break