import sys

n,v = map(int,raw_input().strip().split(" "))
g = [[] for i in range(n)]
for _ in range (v):
	a,b = map(int,raw_input().strip().split(" "))
	g[a].append(b)
	# g[b].append(a)
print(g)