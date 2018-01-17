import sys

arr = raw_input().strip()
b = []
for i in range(len(arr)):
	if(arr[i]== '(' or arr[i]=="{" or arr[i]=="["):
		b.append(arr[i])
	elif(arr[i]==")"):
		if(b.pop() != '('):
			#print("yolo")
			break
	elif(arr[i]=="}"):
		if(b.pop() != '{'):
			#print("yolo")
			break
	elif(arr[i]=="]"):
		if(b.pop() != '{'):
			#print("yolo")
			break
if(len(b)==0):
	print("yes")
else:print("yolo")

