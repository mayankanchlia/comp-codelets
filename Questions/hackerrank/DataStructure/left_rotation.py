# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
n , d = map(int,raw_input().strip().split(" "))
arr = map(int,raw_input().strip().split(" "))
arr1 = [[0]*1 for i in range(n)]
for i in range (n):
	if(i < d):
		arr1[n+i-d] = arr[i]
	else:
		arr1[i-d] = arr[i]
print ' '.join(map(str, arr1))
