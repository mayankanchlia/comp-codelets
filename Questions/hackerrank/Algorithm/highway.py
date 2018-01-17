import math
fastExp = [[0] for i in range(1123)]
def fast_exp(base,exp):
	if (exp == 1):
		fastExp[exp]=base
	else:
		if (exp % 2 == 0):
			base1 = math.pow(fast_exp(base, exp / 2), 2)
			if (base1 >= mod):
				fastExp[exp] =  base1%mod
			else:
				fastExp[exp] = base1
			
		else:
			ans = (base*(fast_exp(base,(exp - 1) / 2)** 2))
			if (ans >= mod):
				fastExp[exp] = ans%mod
			else:
				fastExp[exp] = ans
		return fastExp[exp]
fast_exp(1000,9)