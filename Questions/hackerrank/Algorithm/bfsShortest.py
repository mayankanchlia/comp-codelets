# Enter your code here. Read input from STDIN. Print output to STDOUT
import atexit, io, sys
from Queue import *
 
# A stream implementation using an in-memory bytes 
# buffer. It inherits BufferedIOBase.
buffer = io.BytesIO()
sys.stdout = buffer
 
# print via here
@atexit.register
def write():
    sys.__stdout__.write(buffer.getvalue())
q = int(raw_input().strip())
def bfs(x):
    k =Queue()
    k.put((x,1))
    visited[x] = 1
    while(not k.empty()):
        temp1= k.get()
        temp = temp1[0]
        j = temp1[1]       
        #temp = temp1[0]
        #print(temp,G[temp])
        visited[temp] = 1
        #j=temp1[1]
        for i in range(len(G[temp])):
            #print(i)
            if(visited[G[temp][i]] == 0):
                #print (G[temp][i],j)
                k.put((G[temp][i],j+1))
                if(h[G[temp][i]]==0):
                    h[G[temp][i]] = 6*j
for i in range(q):
    n,m = map(int,raw_input().strip().split(" "))
    G = [[] for i in range(n+1)]
    for i in range(m):
        a,b = map(int,raw_input().strip().split(" "))
        if b not in G[a]:
            G[a].append(b)
        if a not in G[b]:
            G[b].append(a)
    
    s = int(raw_input().strip())
    visited = [0]*(n+1)
    h = [0]*(n+1)
    bfs(s)
    #print(h)
    for i in range(1,n+1):
        if(i !=s and h[i] !=0):
            print(h[i]),
        elif(i!=s and h[i]==0):
            print(-1),
    print
    