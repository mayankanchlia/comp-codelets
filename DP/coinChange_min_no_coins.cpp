#include <iostream>
#include <limits.h>
using namespace std;
int coin[100],sum1,n;
int coin1(){
	int dp[sum1+1] ;
	for(int i =0 ; i <= sum1 ;i++)dp[i] = INT_MAX;
		dp[0] = 0;
	for(int i =1 ; i <= sum1 ; i++){
		for(int j =0 ; j < n ; j++){
			if(coin[j] < i ) {
				int a  = 1 + dp[i-coin[j]];
				if(a<dp[i]) dp[i] = a;  
			}
			else if (coin[j]==i){
				dp[i] = 1;
			}
		}

	}
	for(int i =0 ; i<= sum1 ; i++) cout << dp[i] <<" ";
	return dp[sum1];
}
int main (int argc , char ** argv){
	int t ; t =1;
	while(t--){
		cin   >> sum1 >> n;
		for(int i = 0 ; i< n ; i++)cin >> coin[i];
			cout << coin1() << endl;
	}
}