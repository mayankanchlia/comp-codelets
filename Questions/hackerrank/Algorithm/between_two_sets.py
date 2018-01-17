import sys
def gcd(x,y):
	if (y==0):return x
	return gcd(y,x%y)
n,m = map(int , raw_input().strip().split(" "))
a = map(int,raw_input().strip().split(" "))
b = map(int,raw_input().strip().split(" "))
lcm_a = reduce(lambda x,y:x*y//gcd(x,y),a)
gcd_b = reduce(lambda x,y:gcd(x,y),b)
count=0
i = 1
while(lcm_a*i<=gcd_b):
	if(gcd_b%(lcm_a*i)==0):
		count+=1
		print(gcd_b,lcm_a*i)
	i+=1
print(count)