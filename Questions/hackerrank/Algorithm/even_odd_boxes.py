import sys

def CrossChecker(arr):
	global flag 
	for x in arr:
		if(flag==0):
			y = 0-(x-2)
			issue_arr.append(y)
			#even_issue.append(x)
			flag = 1
		elif(flag==1):
			y = 0-(x-1)
			issue_arr.append(y)
			flag = 0
def checker(x):
	global flag 
	global issue
	if(flag==0 and x%2!=0):
		issue +=1
		flag = 1
	elif(flag==1 and x%2==0):
		issue+=1
		flag = 0
	else:
		if(flag==1):flag=0
		elif(flag==0):flag=1
	return x

t = int(raw_input().strip())
for i in range(t):
	flag = 0
	issue = 0
	odd_issue = []
	even_issue = []
	n = int(raw_input().strip())
	arr = map(lambda x : checker(int(x)),raw_input().strip().split(" "))
	if(issue%2==0 ):
		print(issue/2)
	else:
		flag =0
		issue_arr = []
		CrossChecker(arr)
		if(sum(issue_arr)>0):print('-1')
		else: print(issue/2+1)
