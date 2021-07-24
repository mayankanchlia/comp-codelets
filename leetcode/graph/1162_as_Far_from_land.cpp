#include<iostream>
using namespace std;
int maxDistance(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size()+2, vector<int>(grid.size()+2, 0));
    int n = grid.size();
    for(int i =0 ; i<n ; i++){
        for(int j =0 ; j < n ; j++){
            if(i == 0 || j == 0 ) dp[i][j] = 0 ;
            else{
                if(grid[i-1][j-1] == 0){
                    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
    }
    for(int i =n ; i>0 ; i--){
       for(int j =n ; j > 0 ; j--){
               if(grid[i-1][j-1] == 0){
                   dp[i][j] = min(dp[i][j], min(dp[i-1][j], dp[i][j-1])+1);
               }
               else{
                   dp[i][j] = 0;
               }
        }
    }
    for(int i =0 ; i<n ; i++){
        for(int j =0 ; j < n ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int main(int argc, char ** argv){
    int n; cin >> n >> endl;
    vector<vector<int>> grid(n, vector<int>(n,1)) ;
    for(int i =0 ; i< n ; i++){
        for(int j = 0 ; j < n ; j++)cin >> grid[i][j];
    }

}