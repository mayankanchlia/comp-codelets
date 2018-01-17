#include <iostream>
using namespace std;
int n , arr[11234];
void func(){
	int max_count=0;
	for(int i =0 ; i < n ; i ++){
		int count = 2;
		for(int j = i+1 ; j < n ; j++){
			int diff = arr[j] - arr[i];
			//count++;
			for(int k = j+1 ; k < n ; k++){
				if(arr[j]+diff == arr[k]){
					//cout << i << " " << j << " " << k << " " << endl;
					count++;
					j = k;
				}
			}
		}
		if(count > max_count) max_count = count;
	}
	cout << max_count << endl;
}
int main (int argc , char ** argv){
	int t ;
	cin >> t;
	while(t--){
		cin >> n ;
		for(int i = 0 ; i < n ; i++){
			cin >> arr[i];
		}
		func();
	}
}