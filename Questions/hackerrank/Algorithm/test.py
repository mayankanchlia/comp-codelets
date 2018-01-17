import sys

n = int(raw_input().strip())
a = map(int,raw_input().strip().split(' '))
m = int(raw_input().strip())
b = map(int,raw_input().strip().split(' '))
com = []
i =0 
j =0 
while(i<len(a) and j<len(b)):
	if(a[i]==b[j]):
		com.append(a[i])
		#print(i , j)
		i+=1
		j+=1
	elif(a[i]<b[j]):
		i+=1
	elif (a[i]>b[j]):
		j+=1
print(i,j)
# while(i<len(a)):
# 	if(a[i]==b[j-1]):
# 		com.append(a[i])
# 	i+=1
# while(j<len(b)):
# 	if(a[i-1]==b[j]):
# 		com.append(b[j])
# 	j+=1
# while(i<len(a)):
# 	if(a[i]==b[len(b)-1]):
# 		com.append(a[i])
# 		i+=1
# 	i+=1
# while(j<len(b)):
# 	if(a[len(a)-1]==b[j]):
# 		com.append(b[j])
# 		j+=1
# 	j+=1

print(len(com))
print(com)
