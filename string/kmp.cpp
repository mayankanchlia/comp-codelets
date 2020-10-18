#include<bits/stdc++.h>
using namespace std;
void computeLPS(int * arr, string p){
    int i =0,len = 0 ;
    arr[i++] =0;
    while(i< p.length()){
        if(p[i] == p[len]){
            arr[i++]= ++len;
        }else{
            if(len!=0) len = arr[len-1];
            else {
                arr[i] = len;
                i++;
            }
        }
    }
}
int main(int argc, char ** argv){
    int n ; 
    cin >> n ;
    while(n--){
        string s, p ;
        cin >> s >> p;
        int arr[p.length()];
        computeLPS(arr,p);
        for(int i = 0 ; i< p.length();i++){
            cout << arr[i] << " ";
        }
        cout << endl;
        int i = 0, j =0;
        while(i<s.length()){
            if(s[i] == p[j]){
                i++;j++;
            }
            if(j == p.length()){
                cout << "found at "<< i-j << endl;
                j = arr[j-1];
            }else if (i < s.length() && s[i]!=p[j]) {
                    if(j!=0) j = arr[j-1];
                    else i++;
            }
        }
    }
    return 0;
}