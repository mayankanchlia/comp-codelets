#!/bin/python

import sys

def maxScoreOfVincent(n, s, t):
    # Complete this function
    score = 0
    for i in range(n):
        if(s[i]!=t[i] and s[i]!='.'):
            score += 1
    return score        
    
#  Return the maximum score of Vincent.
n = int(raw_input().strip())
s = raw_input().strip()
t = raw_input().strip()
result = maxScoreOfVincent(n, s, t)
print(result)
