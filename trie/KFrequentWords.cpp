#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX_SIZE = 112345;
char * arr[MAX_SIZE];
int hashDb[MAX_SIZE][2];
unsigned long hashFunc(char * str){
    unsigned long hash = 5381;
    int c ;
    while(c = *str++){
        hash = ((hash << 5) + hash) + c;
    }
    return hash%MAX_SIZE;
}

int main(int argc , char ** argv){
    int t; cin >> t;
    while(t--){
        int n ; cin >> n ;
        for(int i =0 ; i < n ;i++){
            char str[1123]; cin >> str;
            arr[i] = str;
            hashDb[hashFunc(str)][0] = i;
            hashDb[hashFunc(str)][1]++;
        }
        int m ; cin >> m ;
        for(int i =0 ; i< m ; i++){
            char str[1123];cin >> str;
            cout << str << endl;
            unsigned long hashValue = hashFunc(str);
            cout << arr[hashDb[hashValue][0]] << " " << hashDb[hashValue][1] << endl;  
        }
    }
}
