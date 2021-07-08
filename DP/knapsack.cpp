#include<vector>
#include<iostream> 
using namespace std;

void knapsack_bounded(vector<int>weights, vector<int> values ,int target){
    vector<vector<int>> dp(weights.size()+1, vector<int>(target+1,0));
    //dp[i][j] is max value when weight is j and given i number of items
    for(int i =0 ; i <= weights.size() ; i++){
        for(int j = 0 ; j <= target; j++){
            if(i == 0 || j == 0) dp[i][j] =0;
            else if(weights[i-1] <= j ){
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weights[i-1]] + values[i-1]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i =0 ; i <= weights.size() ; i++){
        for(int j = 0 ; j <= target; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
void knapsack_unbounded(vector<int>weights, vector<int> values ,int target){
    vector<int> dp(target+1,0);
    //dp[i][j] is max value when weight is j and given i number of items
    for(int  i = 0 ; i<=target ; i++){
        for(int j = 0 ; j <= weights.size(); j++){
            if(weights[j-1] <= i)
                dp[i] = max(dp[i] , dp[i - weights[j-1]] + values[j-1]);
        }
    }
    for(int  i = 0 ; i<=target ; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
}
int knapsack_hackerrank(vector<int>weights,int target){
    vector<int> dp(target+1,0);
    //dp[i][j] is max value when weight is j and given i number of items
    for(int  i = 0 ; i<=target ; i++){
        for(int j = 0 ; j <= weights.size(); j++){
            if(weights[j-1] <= i)
                dp[i] = max(dp[i] , dp[i - weights[j-1]] + weights[j-1] );
        }
    }
    return dp[target];
}
int main(int argc, char ** argv){
    int t ; cin >> t ;
    while(t--){
        int n, target ; cin >> n  >> target;
        vector<int> weights(n), values(n);
        for(auto i = 0 ; i < n ; i ++){
            cin >> weights[i];
        }
        // for(auto i = 0 ; i < n ; i ++){
        //     cin >> values[i];
        // }
        knapsack_hackerrank(weights, target);
    }
}