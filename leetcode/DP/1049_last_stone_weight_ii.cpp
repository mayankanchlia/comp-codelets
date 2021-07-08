#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
// int lastStoneWeightII(vector<int>&stones){
//     int sum = 0 ; 
//     for(auto i : stones)sum+= i;
//     vector<int> dp(1501, 0);
//     for(int i = sum/2, i >=)
// }

// int snapsack(vector<int> weights, vector<int> value, int targetSum){
//     int dp[1234][1234];
//     for(int i =0 ; i <= weights.size() ; i ++){
//         for(int j = 0 ; j <= targetSum; j++) {
//             if(i ==0 || j == 0)dp[i][j] = 0;
//             if(weights[i-1] <= j ){
//                 dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j-weights[i-1]]);
//             }else{
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     for(int i =0 ; i <= weights.size() ; i ++){
//         for(int j = 0 ; j <= targetSum; j++) {
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
    
// }
int lastStoneWeightII(vector<int> &stones){
    int sum_1 = 0;
    for(auto i : stones ) sum_1+= i;
    cout << sum_1 << endl;
    int dp[stones.size() + 1][sum_1/2 +1];
    sort(stones.begin(), stones.end());
    for(auto i : stones ) cout << i << " ";
    cout << endl;
    for(int i =0 ; i <= stones.size() ; i++){
        for(int j = 0 ; j <= (sum_1/2) +1 ; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else if(stones[i-1] <= j ) dp[i][j] = max(dp[i-1][j], stones[i-1] + dp[i-1][j - stones[i-1]]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    for(int i =0 ; i <= stones.size() ; i++){
        for(int j = 0 ; j <= sum_1/2 +1 ; j++){
            cout << dp[i][j] <<  " ";
        }
        cout << endl;
    }
    return abs(sum_1 - (2* dp[stones.size()][(sum_1/2)+1] ));
}
int main(int argc, char ** argv){
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ;
        vector<int> stones(n); 
        for(int i = 0 ; i < n ; i++) cin >> stones[i];
        // vector<int> value(n);
        // for(int i = 0 ; i < n ; i++) cin >> value[i];
        // snapsack(stones,value,targetSum);
        cout << lastStoneWeightII(stones)<< endl;
    }
    return 0;
}