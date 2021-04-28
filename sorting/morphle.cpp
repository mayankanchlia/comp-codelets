#include<bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
    int n, k ; 
    cin >> n >> k ;
    vector<string> str_list;
    for(int i = 0 ; i < k ; i++){
        string s ; cin >> s;
        str_list.push_back(s);
    }
    queue<string> q;
    for(int j=0; j<str_list[0].length(); j++){
        string abc ;
		q.push(abc+str_list[0][j]);
    }
    for(int i=1; i<k; i++){
        int size = q.size();
        while(size--){
            string s1 = q.front();
            q.pop();
            for(int j=0; j<str_list[i].length(); j++){
                // cout << s1 <<str_list[i][j] << endl;
                q.push(s1+str_list[i][j]);
            }
        }
        // cout << endl;
	}
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
}