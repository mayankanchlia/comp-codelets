from sys import stdin
s = stdin.readline().strip()
k,b,d = map(int,raw_input().strip().split(" "))
sum1 = 0 
print(int(str(d),10))
for i in range(len(s)-k+1):
	sum1 = sum1 + (int(s[i:i+k])%d)
print(sum1);