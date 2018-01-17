#include <iostream>
using namespace std;
int n , m ;
int ar1[11234], ar2[11234];
void LCIS(){
	int dp[n+1];
	for(int i =0 ; i< n ; i++){
		int current = 0;
		for(int j = 0 ; j < m ;j++){
			if(ar1[i]==ar2[j]){
				dp[i]
			}
		}
	}
}
int main (int argc ,char ** argv){
	int t ; cin >> t; 
	while(t--){
		cin >> n >> m; 
		for(int i =0 ; i <  n ;i++)cin >> ar1[i];
		for(int i =0 ; i < m ; i++) cin >> ar2[i];
	}
}