#include <iostream>
using namespace std;
int  n, s;
int dp[1123][1123];
void func(int index , int sum){
	if(sum == s && index == n){
		count++;
		return; 
	}	
	if(sum> s || index>n )return;
	if(index==0){
		for(int i =1 ; i< 10; i++){
			func(index+1,sum+i);
		}
	}
	else {
		for(int i = 0 ; i< 10 ; i++){
			//cout << sum << endl;
			func(index+1,sum+i);
		}
	}
	return ;
}
int main(int argc , char ** argv){
	cin >> n >> s;
	func(0,0);
}