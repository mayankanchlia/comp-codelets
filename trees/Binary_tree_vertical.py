import sys
from Queue import *
class Node:
	def __init__ (self,key):
		self.data=key
		self.right=None
		self.left= None
class Tree:
	def __init__(self):
		self.root = Node
def minMax(root,min,max,hd):
    if(root==None):return
    if(hd < min[0]):min[0] = hd
    if(hd>max[0]):max[0] = hd
    minMax(root.left,min,max,hd-1)
    minMax(root.right,min,max,hd+1)
def linePrint(root,lineNo,hd):
    if(root==None):return
    if(hd==lineNo):
        print(root.data),
    linePrint(root.left,lineNo,hd-1)
    linePrint(root.right,lineNo,hd+1)
def levelOrder(root):
   #Write code Here
    q = Queue() 
    q.put(root)
    while(q.qsize()!=0):
    	nodeCount = q.qsize()
    	while(nodeCount):
       		root = q.get()
        	print(root.data),
        	if(root.left):
        		q.put(root.left)
        	if(root.right):
        		q.put(root.right)
        	nodeCount-=1
        print('\n'),
def TopViewAcoodringToHackerRank(root):
   #Write code Here
    if root is None:return
    q = Queue() 
    q.put([root,0,1,1])
    m = dict()
    while(q.qsize()!=0):
        nodeCount = q.qsize()
        c = q.get()
        hd = c[1]
        root = c[0]
        left_counter = c[2]
        right_counter = c[3]
        if hd in m:
            m[hd].append(root.data)
        else:
            m[hd] = [root.data]
        #print(root.data),
        if(root.left and left_counter):
            right_counter = 0
            left_counter = 1
            q.put([root.left,hd-1,left_counter,right_counter])
        if(root.right and left_counter):
            right_counter = 1
            left_counter = 0
            q.put([root.right,hd+1,left_counter,right_counter])
    #print(m)
    for index,value in enumerate(sorted(m)):
        print(m[value][0])
        
def getVerticalOrder(root,hd,m):
    if root is None:
        return
    if hd in m:
        #print(hd)
        m[hd].append(root.data)
    else:
        m[hd] = [root.data]
    if(root.left):
        getVerticalOrder(root.left,hd-1,m)
    if(root.right):
        getVerticalOrder(root.right,hd+1,m)
def printVerticalOrder(root):
    m = {}
    hd = 0
    getVerticalOrder(root,hd,m)
    print(m)
    for index,value in enumerate(sorted(m)):
        print(m[value][0])
        


root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.right = Node(5)
root.left.left = Node(4)
root.right.left = Node(6)
root.right.right = Node(7)
root.right.left.right = Node(8)
root.right.right.right = Node(9)

levelOrder1(root)
min = [0]
max = [0]
#minMax(root,min,max,0)
#printVerticalOrder(root)
# for i in range(min[0],max[0]+1):
#     linePrint(root,i,0)
#     print
# print(min,max)