#include<iostream>
#include<vector>
using namespace std;
int change(int amount, vector<int>& coins) {
        vector<int> dp(5001,0);
        dp[0] =1;
        for(int i = 0 ; i<coins.size() ; i++){
            for(int j = 1 ; j <=amount; j++){
                if(coins[i] <= j){
                    dp[j] += dp[j- coins[i]] ;
                }
            }
        }
        // for(int i =0 ; i <= amount ; i++){
        //     cout << dp[i] << " ";
        // }
        // cout << endl;
        return dp[amount];
    }
int main(int argc, char ** argv){
    int n ; cin >> n ;
    vector<int> coin
}