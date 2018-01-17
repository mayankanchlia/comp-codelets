#include <bits/stdc++.h>
using namespace std;
void lcs(){
	
}
int main(int argc ,char ** argv){
	string s;
	cin >> s;
	cout << s << endl;
	int n = s.length();
	string y ="";
	for(int i = 0 ; i< n ; i++){
		y += s[n-i-1];
	}
	cout <<  y<< endl;
	int dp[n+1][n+1] ;
	//memset(dp,0);
	for(int i =0 ; i<= n ; i++){
		for(int j = 0 ; j<= n ; j++){
			dp[i][j] = 0;
		}
	}
	for(int j =0 ; j <= n ; j++){
		for(int i= 0 ; i <= n ; i++){
			//cout << s[i-1] << " " << s[n-j-1]<<endl;
			if( i==0 || j==0 ) dp[i][j]=0;
			else if((s[j-1]) == y[i-1]){
			cout << i-1 << " " << j-1<<endl;
				dp[i][j] = 1+ dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	for(int i =0 ; i <= n ; i++){
		for(int j =0; j<=n ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	int val = dp[n][n];
	char arr[1234];
	int i = n , j = n,h=0;
	while(val!=0 ){
		if(s[i-1]==y[j-1]){
			//cout << str2[i-1] << endl;
			arr[h++] = s[i-1];
			i--; j--;
			val--;
		}
		else {
			if(dp[j-1][i] > dp[j][i-1]){
				j--;
			}
			else{
				i--;
			}
		}
	}

	for(int i = h-1 ; i>=0 ;i--)cout << arr[i] << " ";
		cout << endl;
}