import sys
class Node:
	def __init__(self,data):
		self.data = data
		self.next = None
class Linkedlist:
	def __init__(self):
		self.head = None
def printL(head):
	while(head):
		print(head.data)
		head = head.next
n = int(raw_input())
llist = Linkedlist()
llist.head = Node(raw_input().strip())
a = llist.head
for i in range(n):
	temp = Node(raw_input().strip())
	a.next = temp
	a = a.next
pr = llist.head
while(pr):
	print(pr.data)
	prev = pr
	pr = pr.next
prev.next = Node(12)
#print(pr.data)
pr = llist.head
while(pr):
	print(pr.data)
	pr = pr.next

# n= int(raw_input().strip())
# map(lambda x : insert(x),raw_input().strip().split())
