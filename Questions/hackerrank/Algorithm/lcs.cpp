#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int lcs(string arrA,string arrB, int m,int n){
		int L[m+1][n+1] , i , j;
		for (i =1; i<=m ;i++){
			for (j=1;j<=n;j++){
				if(i==1|| j==) L[i][j] = 0;
				if (arrA[i-1]==arrB[j-1]) L[i][j] = L[i-1][j-1] +1;
				else L[i][j] = max(L[i][j-1],L[i-1][j]);
			}
		}
		return L[m][n];
	}



int main() {
	string arrA;    	
	string arrB;
	cin >> arrA>>arrB;
	// cout << arrA << endl;
	// cout << arrB << endl;
	// cout<<arrB.length()<<endl;
	cout << lcs(arrA,arrB,arrA.length(),arrB.length());

    return 0;
}
