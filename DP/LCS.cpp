#include <iostream>
using namespace std;
int str1[100],str2[100], arr[100];
int n , m,h;
void lcs(){
	int dp[m+1][n+1];
	for(int i = 0 ; i <= m ; i++){
		for(int j = 0 ; j <= n ; j++){
			if(i==0 || j == 0) dp[i][j] = 0;
			else if(str1[j-1] == str2[i-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] =  max(dp[i-1][j] , dp[i][j-1]);
		}
	}
	int val = dp[m][n];
	
	int i = m , j = n;
	while(val!=0 ){
		if(str1[j-1]==str2[i-1]){
			//cout << str2[i-1] << endl;
			arr[h++] = str2[i-1];
			i--; j--;
			val--;
		}
		else {
			if(dp[i-1][j] > dp[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}

	for(int i = h-1 ; i>=0 ;i--)cout << arr[i] << " ";
		cout << endl;

}
int main (int argc , char **  argv){
	int t ; t=1;
	while(t--){
		cin >> n >>   m ;
		//cout << n << " " << m << endl;
		for(int i=0 ; i < n ; i++) cin >> str1[i];
		for(int j =0 ; j < m ; j ++) cin >> str2[j];
		lcs() ;
	}	
}