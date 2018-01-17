def max_s(a, b):
    if(len(a)>len(b)): return a
    elif(len(a)<len(b)): return b
    else:
        if(int(a)>int(b)) : return a
        else : return b
n = int(raw_input())
arr1 = [0 for i in range(9)]
arr = [n/int(x) for x in raw_input().split() ]
#print arr
for  i  in range(9):
    arr1[i] = arr[i],i+1 
arr1.sort(reverse = False)
i = 0
a1 = []
#print arr1-1
# while(i<9):
#     while(i<8 and arr1[i][0]==arr1[i+1][0]):
#         i+=1
#     a1.append([arr1[i][0],str(arr1[i][1])])
#     i+=1
print arr1
if (arr1[8][0]>0):
    print str(arr1[8][1])*arr1[8][0]
else :
    print -1
#print a1[0][1]

# dp =  [str(0) for i in xrange(n+1)]
# for i in xrange(1,n+1):
#     for j in xrange(len(a1)):
#         if(i >= a1[j][0]):
#             if(dp[i-a1[j][0]]!= '0' and dp[i] != '0' ):
#                 dp[i] = max_s( dp[i], a1[j][1] + dp[i-a1[j][0]])
#             elif(dp[i-a1[j][0]]=='0' and dp[i] != '0'):
#                 dp[i] = max_s(dp[i],str(a1[j][1]))
#             elif(dp[i] =='0' and dp[i-a1[j][0]] != '0'):
#                 dp[i] = (str(a1[j][1]) + dp[i-a1[j][0]])
#             else :
#                 dp[i] = str(a1[j][1])
# if(dp[n] == 0):
#     print -1
# else:
#     print dp[n]