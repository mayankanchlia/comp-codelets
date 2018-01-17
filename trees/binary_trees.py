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

root = Node(3)
root.left = Node(5)
root.right = Node(6)
root.left.right = Node(8)
root.left.left = Node(7)

root.right.left = Node(9)
root.right.right = Node(11)
levelOrder(root)