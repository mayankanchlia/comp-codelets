#include<iostream>
#include<vector> 
using namespace std;
int mincostTickets(vector<int>& days, vector<int>& costs) { 
    vector<bool> visitingDays(366,false);
    for( auto i : days) visitingDays[i] = true;
    vector<int> dp(366,0);
    for(int i =1 ; i < 366; i++){
        if(visitingDays[i]){
            if(i>=30)dp[i] = min(min(dp[i-1] + costs[0], dp[i-7]+ costs[1]), dp[i-30]+ costs[2]);
            else if(i>=7)  dp[i] = min(min(dp[i-1] + costs[0], dp[i-7]+ costs[1]), costs[2]);
            else if(i>=1)  dp[i] = min(min(dp[i-1] + costs[0], costs[1]), costs[2]);
        } 
        else dp[i] = dp[i-1];
    }
    for(int i =0 ; i < 366; i++){
        cout << dp[i] << " " ;
    }
    cout << endl;
    return dp[days[days.size()-1]];
}
int main(int argc, char ** argv){
    int t ; cin >> t;
    while(t--){
        int n ; cin >> n ;
        vector<int> days(n,0);
        for(int i  = 0 ; i < n ; i++)cin >> days[i];
        for(int i  = 0 ; i < n ; i++)cout << days[i] << " ";
        cout << endl;
        vector<int> costs(3,0);
        for(int i  = 0 ; i < 3 ; i++)cin >> costs[i];
        for(int i  = 0 ; i < 3 ; i++)cout << costs[i] << " ";
        cout << endl;
       int ans = mincostTickets(days,costs) ;
       cout << ans << endl;
    }
    return 0;
}