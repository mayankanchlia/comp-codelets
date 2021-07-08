#include<iostream>
#include<vector>
using namespace std;
int findTargetSumWays(vector<int> &nums, int S){
    int sum  = 0;
    for(auto s : nums) sum += s;
    if(S> sum) return 0;
    if((sum+ S) % 2 != 0) return 0;
    int target = (sum+S)/2;
    vector<vector<int>> dp(nums.size()+1, vector<int>(target + 1 , 0));
    dp[0][0] = 1;
    for(int i =1 ; i <= nums.size() ; i++){
        for(int j = 0 ; j <= target; j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            }else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[nums.size()][target];
}
int findTargetSumWaysRecurssion(vector<int> &nums, int S){
    
}
int main(int argc, char ** argv){
    int t ; cin >> t;
    while(t--){
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for(int i =0 ; i < n ; i++) cin >> nums[i] ;
        findTargetSumWays(nums,target);
    }
    return 0;
}