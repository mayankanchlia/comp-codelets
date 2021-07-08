#include<iostream>
#include<vector>
#include<string>
using namespace std;
int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[strs.size()+1][m+1][n+1]; 
        int preProcess[strs.size()][2];
        for(int j = 0 ; j < strs.size() ; j++){
            int zeros = 0;
            for (auto i : strs[j]) if (i == '0')zeros++;
            preProcess[j][0] = zeros;
            preProcess[j][1] = strs[j].length() - zeros;
        }
        for(int j = 0 ; j < strs.size() ; j++){
            cout << preProcess[j][0] <<  preProcess[j][1] << endl;
        }
        cout << endl;
        for(int k = 0 ; k <= strs.size() ; k++){
            for(int i =0 ; i <= m ; i++){
                for(int j = 0 ; j <= n ; j++){
                    if(k == 0)dp[k][i][j] =0;
                    else if(preProcess[k-1][0] <= i && preProcess[k-1][1] <= j )
                        dp[k][i][j] = max(dp[k-1][i-preProcess[k-1][0]][j-preProcess[k-1][1]] +1 , dp[k-1][i][j]);
                    else{
                        dp[k][i][j] = dp[k-1][i][j];
                        }
                }
            }
        }
        for(int k = 0 ; k <= strs.size() ; k++){
            for(int i =0 ; i <= m ; i++){
                for(int j = 0 ; j <= n ; j++){
                    cout << dp[k][i][j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return 0;
    }
int main(int argc, char ** argv){
    int t ;cin >> t;
    while(t--){
        int l, m ,n  ;cin >> l >> m >> n ; 
        vector<string> strs(l);
        for(int i =0 ; i < l ; i++)cin >> strs[i];
        findMaxForm(strs,m,n);
    }
    return 0;
}