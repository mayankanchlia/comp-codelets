#include <iostream>
#include <limits.h>
using namespace std;
int n ;int arr[100];
void mat_mul(){
	int dp[n+1][n+1];
	for(int i = 0 ; i <= n ; i++) for(int j = 0 ; j <= n ; j++) dp[i][j] = 0;
	for(int L = 2 ; L <= n ; L++){
		for(int i = 0 ; i < n-L +1 ;i++){
			int j = i+L-1 ;
			dp[i][j] = INT_MAX;

			for(int k = i ; k<=j-1;k++){
				int q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
				   if (q < dp[i][j])
                    dp[i][j] = q;
			
			}
		}
	}
	for(int i = 0 ; i<n ; i++){
		for(int j =0 ; j < n ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
int main (int argc , char ** argv){
	int t ; cin >> t;
	while
		(t--){
		cin >> n;
		for(int i =0 ; i< n ; i++) cin >> arr[i];
		mat_mul();
	}
}