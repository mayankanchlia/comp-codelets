#include <bits/stdc++.h>
using namespace std;
int main(int argc , char ** argv){
	int n , e;
	cin >> n >> e;
	int dp[n+1][e+1];
	for(int i =0 ; i<= e ; i++){
		dp[0][i] = 0;
	}
	for(int i =1 ; i <= n ; i++){
		for(int j =1 ; j <= e ; j++){
			//if (i==0)dp[i][j] = 0;
			if(i==1) dp[i][j] = 1;
			else if (j ==1) dp[i][j] = i;
			else {
				 dp[i][j] = INT_MAX;
				for(int  k =1 ;  k < i ; k++ ){
					dp[i][j] = min(dp[i][j],max(dp[i-k][j],dp[k-1][j-1])+1);
				}	
			}
		}
	}
	for(int i = 1; i<= n ; i++){
		for(int  j =1 ; j <= e ; j++){
			cout << dp[i][j] <<" ";
		}
		cout << endl;
	}
}