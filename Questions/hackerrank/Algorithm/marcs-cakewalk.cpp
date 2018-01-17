#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main (){
	int n;
	long long int sum = 0;
	cin >> n;
	vector<int>c(n);
	for (int i = 0;i<n;i++) cin>>c[i];

	sort(c.rbegin(), c.rend());
//cout <<c[1];
	for(int j =0 ;j <n;j++){
		sum = sum + c[j]*pow(2,j);
//		cout << sum << endl;
	}
	cout << sum;
	return 0;


}