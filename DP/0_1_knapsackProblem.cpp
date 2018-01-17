#include <iostream>
#include <algorithm>
using namespace std;
int weig[2000],val[2000];
int n ;
int val_sum, weig_sum, max_val , sum1;

void knap_rec(int index){

	if(index == n){
		if(max_val < sum1) max_val = sum1;
		return ;
	}
	if(sum1 + weig[index] <= weig_sum){
		sum1 += weig[index];
		knap_rec(index);
		knap_rec(index+1);
		sum1 -= weig[index];
	}
	knap_rec(index+1);

}
int knap_dp_unbounded(){
	int dp[weig_sum+1];
	for(int i =0 ; i <= weig_sum ; i++) dp[i] = 0;

	for(int i =1 ; i <= weig_sum ; i ++){
		for(int j =0 ; j <= n ; j++){
			//if(i==0 || j==0) dp[i] = 0;
			 if (i >= weig[j] ) dp[i] = max( dp[i] , weig[j] + dp[i - weig[j]]);
			 
		}
	}
	for(int i = 0 ; i <= weig_sum ; i++) cout << dp[i] << " ";
			 	cout << endl;
	return dp[weig_sum];
}
int main (int argc, char ** argv){
	int t ;cin >> t;
	while(t--){
		cin >> n >> weig_sum;
		sum1 = 0;
		max_val = 0;
		weig[0] = 0;
		val[0] = 0;
		for(int i = 0 ; i < n ; i++)  cin >> weig[i];
		//for(int i = 0 ; i < n ; i++)  cin >> val[i];
		cout << knap_dp_unbounded();
		//cout << max_val << endl;
	}

}