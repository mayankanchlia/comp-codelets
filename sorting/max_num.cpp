#include<iostream>
using namespace std;

int max_num(int a, int b, int c)
{
 
    if (b > c || b >a )return -1;
    int val = c - b;
    int div = (c - b) / a;
    int ans = div * a + b; 
    return ans;
}
int main(int argc, char ** argv){
    int t ; cin >> t ;
    while(t--){
        int a , b , c ; 
        cin >> a >> b >> c ;
        cout << max_num(a,b,c) << endl;
    }
}
 