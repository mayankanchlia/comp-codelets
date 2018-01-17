import sys
from Queue import *
class Node:
	def __init__ (self,key):
		self.data=key
		self.right=None
		self.left= None
def levelOrder(root):
    q = Queue() 
    q.put(root)
    while(q.qsize()!=0):
       	root = q.get()
        print(root.data)
        if(root.left):
        	q.put(root.left)
        if(root.right):
        	q.put(root.right)

root = Node(1)
root.left = Node(2)
root.right = Node(3)
root.left.left = Node(4)
root.left.right = Node(5)
root.right.left = Node(6)
root.right.right = Node(7)
levelOrder(root)