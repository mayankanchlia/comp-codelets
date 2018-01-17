#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
void super_digit(string number,long long int len,int k){
	long long int sum_n=0;
	//cout <<"k"<<k<<endl;
	if (len==1){ cout  << number ;}
	else {
		for(int i = 0;i<len;i++){
			sum_n = sum_n+(number[i] - '0');
			//cout << "summ"<<sum_n<<endl;
			}
			sum_n*=k;
			k = 1;
			number = to_string(sum_n);
			//cout << number<<" nu " << number.length()<<endl;
			//printf("%s\n",number) ;
		super_digit(number,number.length(),k);
		}	
}
	




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string digit,digit_fin;
    int k ;
    cin >> digit >> k;
  //  cout <<digit.length()<<endl;;
    // for(int i =0;i<k;i++) digit_fin=digit_fin+digit;
//    cout << digit_fin<<endl;
  //  cout << "len "<<digit.length();
    super_digit(digit,digit.length(),k);
   // cout <<digit<< " "<<digit.length();
   	//stoi(digit);
 //   	int dig = stoi(digit);
 //   	to_string(dig);
 // cout << digit[2]-'0' + 10;
    
    return 0;
}
