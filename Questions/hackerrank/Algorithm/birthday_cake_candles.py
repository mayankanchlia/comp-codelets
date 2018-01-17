#!/bin/python

import sys
max_count = 0
max1 = 0
count = 0
def abc1(x):
       # Complete this function
    global max_count
    global max1
    if (x>max1):
        max1 = x
        max_count=1
        #print("Adssada")
    elif(x == max1):
        max_count+=1
    return x
n = int(raw_input().strip())
ar = map(lambda x :abc1(int(x)), raw_input().strip().split(' '))
print(max_count)
