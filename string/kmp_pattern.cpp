#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(int * arr, string b) {
	int len = 0 , i =0 ;
	arr[0] = 0;
	i = 1;
	while(i<b.length()){
		if(b[len] == b[i]){
			len++;
			arr[i] = len;
			i++;
		}
		else {
			if(len != 0){
				len = arr[len-1];
			}
			else {
				arr[i] = 0;
				i++;
			}
		}
	}
	for(int i=0 ; i< b.size();i++)cout  << arr[i] << " ";
		cout << endl;
}
void kmpserach(int * lps , string a, string b){
	int n = a.length();
	int m = b.length();
	int i =0 , j = 0;
	while(i<n){
		if(b[j]==a[i]){
			i++;j++;
		}
		if(j==m){
			cout << "yes"<< endl;
			j = lps[j-1];
		}
		else if (i<n && b[j]!= a[i]){
			if(j!= 0) j = lps[j-1];
			else i++;
		}
	}
}
int main (int argc ,char ** argv){
	string a,  b ;
	cin >> a >> b;	
	int lps[b.length()];
	computeLPSArray(lps, b);
	kmpserach(lps,a,b);
}