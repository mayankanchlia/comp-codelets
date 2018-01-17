#!/bin/python

import sys

def onceInATram(x):
    # Complete this function
    left = x[5]+x[4]+x[3]
    right = x[0]+x[2]+x[1]
if __name__ == "__main__":
    x = (raw_input().strip())
    result = onceInATram(x)
    print result
