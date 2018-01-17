# Enter your code here. Read input from STDIN. Print output to STDOUT
import sys
n = int(raw_input())
strings = []
for i in range(n):
	strings.append(raw_input())
print strings
q = int(raw_input().strip())
for i in range(q):
	print(strings.count(raw_input()))