#include <iostream> 
using namespace std;
int n , arr[100] , tar_sum;
void subSetSum (){
	int dp[n+1][tar_sum+1];
	for(int i =0 ; i <= n ; i++){
		for(int j =0 ; j <= tar_sum ; j++){
			if(i==0)dp[i][j] = 0;
			else if ( j == 0) dp[i][j] =1;
			else {
				if(j < arr[i-1]) dp[i][j] = dp[i-1][j];
				//else if(j== arr[i-1]) dp[i][j] = 1;
				else {
					//cout << arr[i-1] << endl;
					dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
				}
			}
		}
	}
	for(int i =0 ; i<=  n ; i++){
		for(int j = 0; j <= tar_sum ; j++){
			cout << dp[i][j]<< " ";
		}
		cout << endl;
	}
}
int main (int argc , char ** argv){
	int t ; cin >> t;
	while(t--){
		cin >> n >> tar_sum ;
		
		for(int i =0 ; i < n ; i++) cin >> arr[i];
		//for(int i =0 ; i < n ; i++) cin >> arr[i];
		subSetSum();
	}
}