#include<iostream>
#include<vector> 
#include<climits>
using namespace std;
int ans = INT_MAX;

// int minStepsHelper (int n , int currentNumber, int currentClipboard,vector<int> dp){
//     if(currentNumber > n){
//         return INT_MAX;
//     }
   
//     if(dp[currentNumber]!=-1){
//         return dp[currentNumber];
//     }
//     int first = minStepsHelper(n,currentNumber+currentClipboard,currentClipboard,dp) +1;
//     int second = INT_MAX;
//     if(currentNumber != currentClipboard){
//         second = minStepsHelper(n,currentNumber,currentNumber,dp) +1;
//     }
//     dp[currentNumber] = min(first,second);
//      if(currentNumber == n){
//         cout << dp[currentNumber] << endl; 
//         // return dp[currentNumber];
//     }
//     return dp[currentNumber];
// }
// int minSteps(int n) {
//     if(n==1)return 0;
//     vector<int> dp(n+1,-1);
//     dp[1] =0;
//     cout << minStepsHelper(n,1,1,dp);
//     return 1;
// }
int minSteps(int n) {
    vector<int> dp(n+1,-1);
    dp[1] = 0;
    for(int i =0 ; i <= n ; i++){
        for(int j = i-1; j>=1 ;j--){
            if(i%j == 0){
                dp[i] = dp[j] + (i/j);
                break;
            }
        }
    }
    return dp[n];
}
int main(int argc, char ** argv){
    int t ; cin >> t;
    while(t--){
        int n ; cin >> n ;
        cout << minSteps(n);
    }
    return 0;
}