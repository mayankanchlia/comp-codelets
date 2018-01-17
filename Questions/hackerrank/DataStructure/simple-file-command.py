import sys , fnmatch
q = int(raw_input().strip())
s = []
for i in range (q):
	cmd =  raw_input().strip()
	if(cmd.split(" ",1)[0] == 'crt'):
		fname = cmd.split(" ",1)[1]
		#print fname
		if fname in s:
			#leng= len(fname)
			count = len(fnmatch.filter(s,fname+'*'))
			#fname = fname+'('+str(count)+')'

			for i in range(1,count+1):
				#print(fname.split("(",1)[0]+'('+str(i)+')')
				if not (fname+'('+str(i)+')') in s:
					fname = fname + '('+str(i)+')'
					break
				# if(not fnmatch.filter(s,fname.split("(",1)[0]+'('+str(i)+')')):
				# 	fname = fname.split("(",1)[0]+'('+str(i)+')'
				# 	break
				else:
					if(i == count):
						fname = fname+'('+str(count)+')'
						break
			s.append(fname)
		else:
			s.append(fname)
		print('+ '+fname)
	elif(cmd.split(" ",1)[0] == 'del'):
		s.remove(cmd.split(" ",1)[1])
		print('- '+ cmd.split(" ",1)[1])
	elif(cmd.split(" ",1)[0] == 'rnm'):
		cmd,f1,f2 = map(str,cmd.strip().split(" "))
		s.remove(f1)
		if f2 in s:
			#leng= len(f2)
			count = len(fnmatch.filter(s,f2+'*'))
			#fname = fname+'('+str(count)+')'
			for i in range(1,count+1):
				#print(fname.split("(",1)[0]+'('+str(i)+')')
				if not (f2+'('+str(i)+')') in s:
					f2 = f2 + '('+str(i)+')'
					break
				else:
					if(i == count):
						f2 = f2+'('+str(count)+')'
						break
			s.append(f2)
		else:
			s.append(f2)
		print('r '+f1+' -> '+f2)
#print(s)
	#print cmd
	# if(cmd == 'crt'):1
	# 	s.append(raw_inp11ut().strip())
	#print(s)
