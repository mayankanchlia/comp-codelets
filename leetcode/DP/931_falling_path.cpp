#include<bits/stdc++.h>
using namespace std;
   int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // cout <<  n << " " << m << endl;
        vector<vector<int>> dp(n, vector<int>(m,0));
        // cout <<  dp.size() << " " << dp[0].size() << endl;
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                // cout << i << " " << j << endl;
                if(i != 0 && j != 0 && j != m-1){
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i-1][j+1]) + matrix[i][j];
                } else if(i != 0 && j != 0 ){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];
                }
                else if(i==0) {
                    dp[i][j] = matrix[i][j];
                }
                else if(i!= 0 && j ==0){
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                }
            }
        }
        int ans = INT_MAX;
        for(int j =0 ; j < m ; j++){
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
        
    }