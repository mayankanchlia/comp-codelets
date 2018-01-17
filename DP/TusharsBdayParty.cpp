#include <bits/stdc++.h>
using namespace std;

int main (int argc ,char ** argv){
	int n , m ,k ;
	int arr[3][n];
	int max_capacity= 0;
	for(int i =0 ; i< n ; i++){
		cin >> arr[0][i];
		max_capacity = max (max_capacity, arr[0][i]);
	}
	for(int i =0 ; i< m ; i++){
		cin >> arr[1][i];
	}
	for(int i =0 ; i< k ; i++){
		cin >> arr[2][i];
	}
	int dp[max_capacity+1];
	dp[0] = 0;
	for(int i =0 ; i <= max_capacity ; i++){
		for(int j = 0 ; j < k ; j++){
			if(arr[1][j] <= i){
				dp[i] = min(dp[i],dp[i-arr[1][j]]+arr[2][i]);
			}
		}
	}


}