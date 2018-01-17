t = int(raw_input().strip())
arr = []
a = 0
num = 1
while(num<t):
    num = 3*(2 * a + 1)
    a +=1
    arr.append(num)

    print(num)
