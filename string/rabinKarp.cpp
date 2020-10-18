#include <bits/stdc++.h>
#define d 256
using namespace std;
int main(int argc, char ** argv){
    string s,p ;
    cin >> s >> p; 
    int q =101;
    int h = 1, hs = 0 , hp = 0;
    for(int i = 1; i < p.length() ; i++){
        h = (h*d)%q;
    }
    for (int i = 0; i < p.length(); i++) 
    { 
        hs = (d * hs + p[i]) % q; 
        hp = (d * hp + s[i]) % q; 
        // cout << hs << " " << p[i] << " " << hp << " " << s[i] << endl;
    } 
    for(int i = 0 ; i< s.length() - p.length() ; i++){
        if(hs == hp){
            cout << "true" << endl;
            return 0;
        }
        if(i < s.length() - p.length()){
            hs = (hs - s[i-p.length()])%q;
            hs = (hs*d + s[i+p.length()])%q;
            if(hs <0){
                hs += q;
            }
        }
    }
    cout << "false" << endl;
    return 0;
}