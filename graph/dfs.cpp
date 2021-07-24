#define MAX_N 11234
#include<iostream>
#include<vector>
using namespace std;
int visited[MAX_N][MAX_N];
int dir[4][2] = {{0,1},{0,-1},{-1,0}, {1,0}};
void dfs(int x , int y, vector<vector<char>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    visited[x][y]  = 1;
    cout << x <<  " " << y << endl;
    if(mat[x][y] == '0') mat[x][y] = '1';
    for(int i =0 ; i < 4 ; ++i){
        int new_x = x+dir[i][0], new_y = y+dir[i][1];
        // cout << "new " << new_x << " " << new_y << endl;
        if(new_x < 0 || new_x >= n||  new_y < 0 || new_y >= m || visited[new_x][new_y] == 1 || mat[new_x][new_y] == 'X') continue;
        dfs(new_x, new_y, mat);
    }
}
void solve(vector<vector<char>>& board) {

    for(int i = 0 ; i < board[0].size() ; ++i){
        if(board[0][i] == '0'){
            board[0][i] = '1';
            dfs(0,i,board);
        }
        if(board[board.size()-1][i] == '0'){
            board[board.size()-1][i] = '1';
            dfs(board.size()-1,i,board);
        }
    }  
    for(int i = 0 ; i < board.size() ; ++i){
        if(board[i][0] == '0'){
            board[i][0] = '1';
            dfs(i,0,board);
        } 
        if(board[i][board[0].size() -1] == '0'){
            board[i][board[0].size()-1] = '1';
            dfs(i,board[0].size()-1, board);
        } 
    }
    for(int i = 0 ; i < board.size() ; ++i){
        for(int j = 0 ; j < board.size(); ++j){
            if(board[i][j] == '1') board[i][j] = '0';
            if(board[i][j] == '0') board[i][j] = 'X';
        }
        // cout << endl;
    }

}
int main(int argc, char ** argv){
    int n,m ; cin >> n >> m; 
    vector<vector<char>> mat(n, vector<char>(m, 0));
    for(int i =0 ; i < n ; ++i)
        for(int j =0 ; j < m ; ++j )
            cin >> mat[i][j];
    for(int i =0 ; i < n ; ++i){
        for(int j =0 ; j < m ; ++j ){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }   
    solve(mat);
    return 0;
}