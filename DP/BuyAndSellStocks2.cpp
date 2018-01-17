#include <iostream>
using namespace std;
int main(int argc , char ** argv){
	int n;cin >> n ;
	int arr[n];
	for(int i = 0 ; i < n ; i++) cin >> arr[i];
	int i = 0 , ans = 0 ;
	while(i<n-1){
		//cout << i ;
		int min1 , max1 ;
		while(i<n-1 && arr[i] >= arr[i+1]){
			//cout << i << endl;
			i++;
		}
		min1 = i;
		if(i==n-1) break;
		//cout << i << endl;
		while(i<n && arr[i] <= arr[i+1]){
			i++;
		}
		max1 = i;
		ans  += arr[max1] - arr[min1];
		//cout << min1 << " " << max1 << endl;
	}
	cout << ans;
}