	#include <iostream>

	using namespace std;
	int main(int argc , char ** argv){
		int a;
		bool flag = false;
		while(1){
			cin >> a;
			//cout << a;
					if(a == 42) {
				flag = true;
				return 0;
			}
			if(!flag){
				cout << a << endl;
			}
	

		}

	}