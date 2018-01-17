#include <iostream>
#include <limits.h>
using namespace std;
int n ;
int keys[100] , freq[100];
int frefinder(int i , int j ){
	int sum =0 ;
	for(int k =i ; k<= j ;k++){
		sum+= freq[k];
	}
	return sum;
}
void optimal(){
	int dp[n+1][n+1];
	for(int i =0 ; i<= n ; i++) for(int j =0 ; j <= n ; j++) dp[i][j] =0;
	for(int L = 1 ; L <= n ; L++){
		for(int i =0 ; i <n-L+1 ; i++){
			int j = i+L-1;
			dp[i][j] = INT_MAX;
			for(int k  =i ; k<=j;k++ ){
				int q = ((k>i) ? dp[i][k-1] :0 )+ ((k<j ) ? dp[k+1][j] : 0) + frefinder(i,j);
				if(q < dp[i][j] ) dp[i][j] = q;
			}
		}
	}
	for(int i =0 ; i < n ; i++){
		for(int j =0 ; j< n ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}
int main (int argc , char ** argv){
	int t ; cin >> t;
	while(t--){
		cin >> n ;
		for(int i =0 ; i < n ; i++)cin >> keys[i];
		for(int i =0 ; i < n ; i++)cin >> freq[i];
		//	cout << frefinder(1,3)<<endl;
		optimal();	
	}
}