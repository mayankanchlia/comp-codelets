#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    long long int min,max_min=10000000;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d", &a[a_i]);
    }
    std::sort (a.begin(), a.begin()+n);
  // cout <<a[2];
    for(int i =1;i<n;i++){
            min = abs(a[i]-a[i-1]) ;
           // cout << min << endl;
             if(min<max_min )max_min = min;}
    cout << max_min;
    // your code goes here
    return 0;
}
