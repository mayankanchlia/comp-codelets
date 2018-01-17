#include  <bits/stdc++.h>
using namespace std;
string max_s(string a , string b){
	if(a.length()>b.length()) return a;
	else if(a.length()<b.length()) return b;
	else {
		for(int i = 0; i < a.length(); ++i){
    		if ((a[i] - '0') < (b[i] - '0'))return b;
    	}
    	return a;
	}
}
int main (int argc ,char ** argv){
	int n ; cin >> n;
	int arr[9];
	for(int i =0 ; i < 9 ;i++)cin >> arr[i];
	vector<string> dp(n+1);
	for(int i =0 ; i<= n ;i++)dp[i]="0";
	for(int i =1 ; i<= n ; i++){
		for(int j = 0 ; j < 9 ; j++){
			if(i>=arr[j]){
				if(dp[i - arr[j]] != "0" && dp[i]!="0"){
					dp[i] = max_s(dp[i],to_string(j+1)+dp[i-arr[j]]);
				}
				else if(dp[i - arr[j]]=="0" && dp[i]!="0"){
					dp[i] = max_s(dp[i],to_string(j+1));
				}
				else if(dp[i - arr[j]]!="0" && dp[i]=="0"){
					dp[i] = to_string(j+1)+dp[i-arr[j]];
				}
				else{
					dp[i] = to_string(j+1);
				}
			}
		}
	}
	if(dp[n]=="0")cout << "-1" << endl;
	else cout << dp[n] <<endl;
    return 0;
}