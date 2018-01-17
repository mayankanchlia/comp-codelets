#!/bin/python

import sys
def apple_checker(x):
    global apple_no
    #print(apple_tres)
    if(x>=apple_tres):apple_no +=1
    return x
def orange_checker(x):
    global orange_no
    #print(orange_tres)
    if(x<=orange_tres):orange_no +=1
    return x    

s,t = map(int,raw_input().strip().split(' '))
a,b = map(int,raw_input().strip().split(' '))
m,n = map(int,raw_input().strip().split(' '))
apple_tres = s-a
apple_no = 0
apple = map(lambda x:apple_checker(int(x)),raw_input().strip().split(' '))
print apple_no
orange_tres = t - b
orange_no =0
orange = map(lambda x : orange_checker(int(x)),raw_input().strip().split(' '))
print orange_no