#include<iostream> 
#include<vector>
#include<climits>
using namespace std;

int helper(int v1, int v2, vector<int> nums, vector<vector<int>> &dp){
    if(v2-v1 +1  < 3)return 0;
    if(dp[v1][v2]!= -1) return dp[v1][v2];
    int mini = INT_MAX;
    for(int i = v1 +1; i< v2 ; i++){
        mini = min(mini, nums[v1]*nums[i]*nums[v2] + helper(v1, i,nums,dp) + helper(i,v2, nums,dp));
    }
    dp[v1][v2] = mini;
    return mini;
}
int minScoreTriangulation(vector<int> & values){
    int n = values.size();
    vector<vector<int>> dp (n,vector<int>(n , -1));
    return helper(0,n-1,values, dp);
}
int minScoreTriangulationTab(vector<int> & values){
    int n = values.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1,0));
    //dp[i][j] = min of score where for left vertex i and right vertex j
    for(int i = 2 ; i< n ; i++){
        for(int left = 0 ; left+ i<n; left++){
            int right = left + i;
            dp[left][right] = INT_MAX;
            for(int k = left +1 ; k < right; k++){
                cout << left << " " << right << " " << k << endl;
                dp[left][right] = min(values[left]*values[right]* values[k] + dp[left][k] + dp[k][right], dp[left][right]);
            }
        }
    }
    for(int i =0 ; i < n ; i++){
        for(int j =0 ; j < n ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dp[0][n-1];
}

int main(int argc, char ** argv){
    int t ; cin >> t;
    while(t--){
        int n ; cin >> n;
        vector<int> edges(n);
        for(auto i = 0 ; i < n ; i++)cin >> edges[i];
        cout << minScoreTriangulationTab(edges) << endl;
    }



    return 0;
}