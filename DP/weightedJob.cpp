#include <bits/stdc++.h>
using namespace std;
struct interval {
	int start , end , val;
};
bool comp(interval a , interval b ){
	return a.end < b.end;
}
bool verla(interval a , interval b ){
	return !(b.start >= a.start && b.start < a.end) && !( a.start >= b.start && a.start < b.end);
}
int main(int argc , char ** argv){
	int t ; cin >> t;
	while(t--){
		int n;
		cin >> n ;
		vector<interval> arr(n);
		for(int i =  0 ; i < n ; i++){
			int a ; cin >> a;
			arr[i].start= a;
		}
		for(int i =  0 ; i < n ; i++){
			int a ; cin >> a;
			arr[i].end = a;
		}
		for(int i =  0 ; i < n ; i++){
			int a ; cin >> a;
			arr[i].val = a;
		}
		sort(arr.begin(),arr.end(),comp);
		vector<int> dp(n);
		for(int i =0 ; i < n ; i++) {
			dp[i] = arr[i].val;
		}
		for(int i =0 ;i < n ; i ++){
			for(int j = 0 ; j < i ; j++){
				if(verla(arr[j],arr[i])){
					dp[i] = max(dp[i],arr[i].val + dp[j]);		
				}
			}
		}
		for(int k = 0 ; k < n ; k++) cout << dp[k] << " ";
			cout << endl;
	}
}