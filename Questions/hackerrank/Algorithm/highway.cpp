	#include<iostream>
	#include <vector>
	#include<math.h>
	#include<algorithm>
	#include<memory.h>
	#define ULL unsigned long long
	#define mod 1000000009
	using namespace std;
	ULL fastExp[1123];
	ULL dp[112345];
	ULL bino[1123][1123];
	ULL fast_exp(ULL base, int exp)
	{
		if (fastExp[exp] == 0) {
			if (exp == 1)
				fastExp[exp]=  base;
			else
			{
				if (exp % 2 == 0)
				{
					ULL base1 = pow(fast_exp(base, exp / 2), 2);
					if (base1 >= mod)
						fastExp[exp] =  base1%mod;
					else
						fastExp[exp] = base1;
				}
				else
				{
					ULL ans = (base*  pow(fast_exp(base, (exp - 1) / 2), 2));
					if (ans >= mod)
						fastExp[exp] = ans%mod;
					else
						fastExp[exp] = ans;
				}

			}
		}
		return fastExp[exp];
	}
	ULL binomialCoeff(ULL n, ULL k)
{
    ULL res = 1;
    if ( k > n - k )
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
	ULL func(ULL n, ULL k) {
		if (dp[k] == 0) {
			ULL sum = 0;
			for (int i = 0; i < k; i++) {
				sum += ((binomialCoeff(k + 1,k+1- i))*(func(n, i)));
			}
			dp[k] = (((fast_exp(n + 1, k + 1) - 1 - sum)) / (k + 1));
		}
		
		return dp[k];
	}
	int main(int argc, char **  argv) {
		ios::sync_with_stdio(0);
		int t;
		cin >> t;
		while (t--) {
			ULL n;
			cin >> n;
			int k;
			cin >> k;
			for (int i = 0; i <= k + 3; i++) {
				dp[i] = 0;
				fastExp[i] = 0;
				for (int j = 0; j <= k + 3; j++) bino[i][j] = 0;
			}
			ULL sum=0;
			if (n > 2) {
				cout << (func(n - 1, k)- 1) %mod<< endl;
			}
			else cout << 0 << endl;
		}
	}