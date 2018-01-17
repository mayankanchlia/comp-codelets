#!/bin/python

import sys

count = 0
s = raw_input().strip()
for i in range(len(s)):
    if(s[i] >= 'A' and s[i]<= 'Z'):
    	count +=1
    	
print(count+1)