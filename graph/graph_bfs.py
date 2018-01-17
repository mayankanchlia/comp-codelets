import sys
from Queue import *
# x
def bfs(x):
	q = Queue()
	q.put(x)
	while(not q.empty()):
		temp = q.get()	
		print(temp),
		visited[temp] = 1
		for j in range(len(G[temp])):
			if(not visited[G[temp][j]]):
				q.put(G[temp][j])
			#print(G[temp][j]) 


n,v = map(int,raw_input().strip().split(" "))
G = [[] for i in range(n)]
for _ in range(v):
	a,b = map(int,raw_input().split(" "))
	G[a].append(b)
	G[b].append(a)
visited = [0]*n
	#G[b].append(a)
#print(G[0][0])
bfs(2)