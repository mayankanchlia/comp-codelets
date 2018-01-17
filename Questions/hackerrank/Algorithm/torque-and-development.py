import sys
def dfs(x):
	

q = int(raw_input().strip())
for i in range(q):
	n,m,lib,road = map(int,raw_input().strip().split(" "))
	G = [[] for i in range(n+1)]
	for i in range(m):
		u,v = map(int,raw_input().strip().split(" "))
		G[a].append(b)
		G[b].append(a)
	visited = [0]*n

	