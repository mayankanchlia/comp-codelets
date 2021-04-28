#include<bits/stdc++.h>
using namespace std;
int main(int argc, char ** argv){
    int t ; cin >> t ;
    while(t--){
        int n ; cin >> n ; 
        priority_queue<int> arr;
        for(int i = 0 ; i < n ; i ++){
            int a ; cin >> a ;
            arr.push(-a);
        }
        vector<int> ans(n);
        int i = 1 , j = n-1;
        ans[0] = -arr.top();
        arr.pop();
        while(i<= j && i < n){
            if(ans[i-1] != -arr.top()) {
                ans[i] = -arr.top();
                arr.pop();
                i++;
            }else{
                ans[j] = -arr.top();
                arr.pop();
                j--;
            }
        }
        for(int i =0 ; i < n ; i++)cout << ans[i] << " ";
        cout << endl;
    }
}