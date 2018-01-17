# Enter your code here. Read input from STDIN. Print output to STDOUT
import atexit, io, sys

buffer = io.BytesIO()
sys.stdout
@atexit.register
def write():
	sys.__stdout__.write(buffer.getvalue())
n,m = map(int,raw_input().strip().split(" "))
arr = [0 for i in range(n)]
max1  = 0 
x = 0
for i in range(m):
    a,b,k = map(int,raw_input().strip().split(" "))

    arr[a-1] = arr[a-1] + k
    if(b<=n): arr[b] -=k
    #print(arr)
for i in arr:
	x = x+i
	if(x>max1):max1 = x

print max1