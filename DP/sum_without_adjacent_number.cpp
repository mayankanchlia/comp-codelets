#include <iostream>
#include <vector>
using namespace std;
int main(int argc ,char ** argv){
	int n;
	cin >> n;
	vector<int> arr(n);
	
	for(int i =0 ; i< n ; i++) cin >> arr[i];
	//for(int i =0 ; i<n ; i++) cout << arr[i] << " ";
	
	vector<int>	dp1(n+1);
	vector<int> dp2(n+1);
	dp1[0] = arr[0]; dp2[0] = 0;
	for(int i =1 ; i < n ; i++){
		dp1[i] = arr[i] + dp2[i-1];
		dp2[i] = dp1[i-1];
	}
	for(int i =0 ; i< n ; i++){
		cout << dp1[i] << " ";
	}
	cout << endl;
	for(int i = 0 ; i< n ; i++){
		cout << dp2[i] << " ";
	}
	cout << endl;
	cout << max(dp1[n-1],dp2[n-1]);
}