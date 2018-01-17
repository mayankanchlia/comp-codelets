import atexit, io, sys

buffer = io.BytesIO()
sys.stdout
@atexit.register
def write():
	sys.__stdout__.write(buffer.getvalue())
n,q = raw_input().strip().split(" ")
n,q = [int(n),int(q)]
#print(n,q)
querry = [[0]*3 for i in range(q)]
for i in range(0,q):
	querry[i] = list(map(int, raw_input().strip().split(" ")))
#print querry
lastAns = 0 
s = [[] for i in range(n)]
for i in range(q):
	if(querry[i][0]==1):
		s[((querry[i][1]^lastAns)%n)].append(querry[i][2])
		#print(s)
	elif(querry[i][0]==2):
	      seq = s[(querry[i][1]^lastAns)%n]
	      size = len(seq)
	      lastAns = seq[querry[i][2]%size]
	      #print(seq)
	      #lastAns = (s[((querry[i][1]^lastAns)%n)][2])%size
	      print(lastAns)