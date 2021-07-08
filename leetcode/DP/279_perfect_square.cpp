#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;
static vector<int> perFectSquare;
bool isPerfectSquare(int n){
    long long a = sqrt(n);
    return a*a == n ;
}
void populatePerfectSquareTable(int n){
    int start = perFectSquare.size() <= 0 ? 1 : perFectSquare[perFectSquare.size()-1] +1;
    for(int i = start; i <=n ; i++){
        if(isPerfectSquare(i)) perFectSquare.push_back(i);
    }
}
int numSquares(int n) {
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;
    dp[1] = 1;
    populatePerfectSquareTable(n);
    for(auto i : perFectSquare){
        cout << i << " ";
    }
    cout << endl;
    for(int i =1 ; i <=n ; i++){
        if(isPerfectSquare(i)){
            dp[i] = 1;
        }else{
            for(int j = perFectSquare.size()-1; j>=0 ;j-- ){
                if(perFectSquare[j] < i){
                    cout << i <<  " " << perFectSquare[j]<< endl;
                    dp[i] = min(dp[i], dp[i - perFectSquare[j]] + dp[perFectSquare[j]]);
                }
            }
        }
    }
    for(int i =0 ; i < dp.size(); i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
}
int main(int argc, char ** argv){
    int t  ; cin >> t;
    while(t--){
        int n ; cin >> n ;
        cout << numSquares(n) << endl;
    }
    return 0;
}