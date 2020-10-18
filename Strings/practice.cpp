#include<bits/stdc++.h>
using namespace std;
int main(int argc , char ** argv){
    vector<string> allStrings;
    int n ; cin >> n ;
    for(int i = 0 ; i< n ; i++){
        string a ;
        cin >> a ;
        allStrings.push_back(a);
    }
    for(int i = 0 ; i < allStrings.size(); i++){
        cout << allStrings[i] << endl;
    }
    return 0;
}
