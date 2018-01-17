#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;
int n , m ;
int mat[100][100];
int DP[100][100];
int minCost(int x,int y){
	if(x < 0 || y < 0 || x>= n || y>= m ) return INT_MAX;
	if(x == 0 && y == 0) return mat[x][y];
	else {
		return mat[x][y] + min(minCost(x-1,y),min(minCost(x-1,y-1),minCost(x,y-1)));
	}
}
int minCostDP(){
	DP[0][0] = mat[0][0];
	for(int i = 1 ; i < n ; i++) DP[i][0] = mat[i][0] + DP[i-1][0];
	for(int i = 1 ; i < m ; i++) DP[0][i] = mat[0][i] + DP[0][i-1];
	for(int i = 1 ; i< n ; i++){
		for(int j =1 ;  j < m ; j++){
			DP[i][j] = mat[i][j]+ min(DP[i-1][j-1],min(DP[i][j-1],DP[i-1][j]));
		}
	}
	for(int i =0 ; i< n ; i++) {for(int j = 0 ; j < m ; j++){ cout << mat[i][j] << " " ;}cout << endl;}
	return DP[n-1][m-1];
}
int main (int argc , char ** argv){
	cin >> n >> m;
	for(int i =0 ; i< n ; i++) for(int j = 0 ; j < m ; j++) cin >> mat[i][j];
	cout << minCost(n-1,m-1) <<endl;
}