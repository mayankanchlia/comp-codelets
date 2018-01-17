#include <iostream>
#include <vector>
#include <queue>
#define ll long long
using namespace std;
int main (int argc, char ** argv){
	int t;
	cin >> t;
	while(t--){
		int n ;
		cin >> n;
		priority_queue <ll> q;
		for(int i = 0 ; i < n ; i++){
			ll a ;
			cin >> a;
			q.push(a); 
		}
		if(n>1){
			ll largest = q.top();
			q.pop();
			ll sum = 0;
			while(q.size() !=1){
				sum+= q.top();
				q.pop();
			}
			ll smallest = q.top();
			ll sum_final = 3*(smallest+largest) + 2*(sum);
			if(sum_final%2 == 0 && sum_final % 3 == 0) cout << sum_final/6<<endl;
			else if (sum_final%2 == 0 && sum_final %3 != 0) cout << sum_final/2<<"/"<<3 <<endl;
			else if (sum_final%2 != 0 && sum_final %3 == 0) cout << sum_final/3<<"/"<<2 <<endl;
			else if (sum_final%2 != 0 && sum_final %3 != 0) cout << sum_final<<"/"<<6<<endl;
		}
		else{
			cout << q.top() <<endl;
		}
	}
}