#include <iostream>
using namespace std;
int main(int argc, char ** argv){
	int n ; cin >> n;
	char arr[112345][32];
	for(int i =0 ; i < n ; i++){
		cin >> arr[i];
	}
	for(int i = 0 ; i< n ; i++){
		cout << arr[i] << endl;
	}
	
}