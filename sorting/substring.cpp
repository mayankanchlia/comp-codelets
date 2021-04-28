#include <iostream> 
using namespace std;

int countSubstringWithEqualEnds(string s,int l,int r) 
{ 
    int result = 0; 
    int n = s.length(); 
  
    // Calculating frequency of each character 
    // in the string. 
    int count[26] = {0}; 
    for (int i=l; i<=r; i++) 
        count[s[i]-'a']++; 
  
    // Computing result using counts 
    for (int i=0; i<26; i++) 
        result += (count[i]*(count[i]+1)/2); 
  
    return result; 
} 
int main(int argc, char ** argv){
    int n,t; cin >> n >> t;
    string a ; cin >> a ; 
    while(t--){
        int l, r ; cin >> l >> r;
        cout << countSubstringWithEqualEnds(a,l-1,r-1) << endl;
    }
    return 0;
}