#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int> adjlist[112345];
int visited[112345];
void bfs(int current){
    queue<int> qq ;
    qq.push(current);
    visited[current] =1 ;
    while(!qq.empty()){
        int top = qq.front(); qq.pop();
        cout << top << " ";
        for(auto i : adjlist[top]){
            if(!visited[i]) {
                qq.push(i);
                visited[i] = 1;
            }
        }
    }
}
int main(int argc ,char ** argv){
    int nodes, edges,x , y;
    cin >> nodes >> edges;
    for(int i =0 ; i < edges ; i++){
        cin >> x >> y;
        adjlist[x].push_back(y);
    }
    bfs(2); 
    return 0;
}