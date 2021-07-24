#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}}; 
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> ret(n, vector<int>(m,0));
    queue<pair<int, int>> qq;
    qq.push({0,0});
    visited[0][0]  = 1;
    for(int  i =0 ; i <  n ; i++){
        for(int j =0 ; j < m ; j++){
            if(!mat[i][i]) qq.push({i,j});
        }
    }
    while(!qq.empty()){
        pair<int, int> current;
        cout << current.first << " " << current.second << endl;
        for(int i =0 ; i < 4 ; i++){
            int new_x = current.first + dir[i][0];
            int new_y = current.first + dir[i][1];
            if(new_x < 0 || new_y < 0 || new_x >= n || new_y >= m)continue;
            ret[new_x][new_y] = ret[current.first][current.second] +1;
        }
    }
    return ret;
}
int main(int argc , char ** argv){
    int n , m ; cin>> n >> m;
    vector<vector<int>> mat(n, vector<int>(m,0));
    
    for(int i =0 ; i < n ; i ++){
        for(int j =0 ; j < m ; j++){
            cin >> mat[i][j];
        }
    }

    
    return 0;
}