#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int count1;
int p_sum(int c, int n,int m){
	
	
	if(m == 0) return 1;
	
	if(c-pow(m,n)>=0){
	//	cout <<"Sa"<< c-pow(m,n)<<endl;
		if(c-pow(m,n) == 0) count1++;
	 return  p_sum(c-pow(m,n),n,m-1) + p_sum(c,n,m-1);}
		 else 
		return p_sum(c,n,m-1);

}



int main(){
 int x,n;
 cin >> x>>n;
 int m;
 float e = (1.0)/n;
 m  = (int)pow(x,e);
 // int arr[m];
	// for (int i= 0;i<m;i++) arr[i]=i+1;
 p_sum(x,n,m);
 cout << count1;


}