#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main(int argc , char ** argv){
	int n ; cin >> n;
	std::vector<std::vector<int> > v(n);
	for(int i = 0 ; i< n ; i++){
		for(int j = 0 ; j <= i ;j++){
			int a ; cin >> a;
			v[i].push_back(a);
		}
	}
	for(int i =0 ; i< n ; i++){
		for(int j =0 ; j< v[i].size();j++){
			cout << v[i][j]<<" ";
		}
		cout << endl;
	}
	int dp[n+1];
	int j = 0;
	dp[0] = v[0][0];
	v[1][0] = v[0][0]+v[1][0];
	v[1][1] = v[0][0]+v[1][1];
	int min1 = INT_MAX;
	for(int i =2 ; i<n ; i++){
		for(int j = 0 ; j < v[i].size();j++){
			v[i][j] = v[i][j]+min(j!=v[i].size()-1?v[i-1][j]:v[i-1][j-1],j!=0?v[i-1][j-1]:v[i-1][j]);
			if(i==n-1) if(min1>v[i][j]) min1 = v[i][j];
		}
	}
	cout << min1 <<endl;
}