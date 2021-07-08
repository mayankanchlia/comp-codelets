#include<iostream>
#include<queue>
using namespace std;

int solve(int n , int t , vector<vector<int>> tasks){
    priority_queue<pair<int,int>> ans;
    for(int i =0 ; i < tasks.size(); i++){
        if( 2* tasks[i][0] - t > 0){
            pair<int, int> temp(tasks[i][1], tasks[i][0]); 
            ans.push_back(temp);
        }
    }
    int count = 0;
    while(!ans.empty() && t>=0){
        count += 
    }
}
int main(int argc, char ** argv){
    int n, t ; cin >>n >> t ;
    vector<vector<int>> task(2, vector<int>(n, 0));
    for(int i = 0 ; i < n ; i++){
        cin >> task[i] ;
    }
    for(int i = 0 ; i < n ; i++){
        cin >> time[i] ;
    }
}