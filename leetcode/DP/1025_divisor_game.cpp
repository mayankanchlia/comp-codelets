#include<iostream>
using namespace std;
int main(int argc, char ** argv){
    int t ; cin >> t;
    while(t--){
        int n ; cin >> n ;
        cout << n % 2 == 0 ? true : false << endl;
    }
    return 0;
}