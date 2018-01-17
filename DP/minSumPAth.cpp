#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int m , n ,min1 = INT_MAX;
int xMove[4] = {1,-1,0,0};
int yMove[4] = {0,0,-1,1};
int visited[100][100];
bool isSafe(vector<vector<int> > arr,int x , int y){
	return x>=0 && x<m && y >=0 && y<n && visited[x][y]==0; 
}
void min_sum(vector<vector<int> > arr, int x , int y,int cou){
	if(cou > min1) return;
	if(x==m-1&& y==n-1){
		//cout << cou+ arr[m-1][n-1]<< endl;
		if(min1 > cou+arr[m-1][n-1]) min1 = cou+arr[m-1][n-1];
		return ;
	}
	for(int i =0 ; i< 4 ; i++){
		int next_x = x+xMove[i];
		int next_y = y + yMove[i];
		if(isSafe(arr,next_x,next_y)){
			visited[next_x][next_y] = 1;
			min_sum(arr,next_x, next_y,cou+arr[x][y]);
			visited[next_x][next_y]=0;
		}
	}
	return;
}
void min_sum1(vector<vector<int> > arr){
	int dp[m+2][n+2] = {0};
	for(int i =0 ; i <= m+1 ; i++){
		for(int j =0 ; j <= n+1 ; j++){
			dp[i][j] = 0;
		}
		}
	for(int i =1 ; i<=m ; i++){
		for(int j =1 ; j <= n ; j++){
			if(j==1) dp[i][j] = dp[i-1][j]+arr[i-1][j-1]; 
			else if(i==1) dp[i][j] = dp[i][j-1]+arr[i-1][j-1]; 
			else dp[i][j] = arr[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(int i =0 ; i <= m+1 ; i++){
		for(int j =0 ; j <= n+1 ; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout <<  dp[m][n] << endl;
}
int main (int argc ,char ** argv){
	cin >>   m >> n;
	vector<vector<int> >arr(m);

	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			int a ; cin >> a;
			arr[i].push_back(a);
		}
	}
	// for(int i =0 ; i < m ; i++){
	// 	for(int j =0 ; j <  n ; j++){
	// 		cout << arr[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	visited[0][0] =1;
	min_sum1(arr);
	//cout << min1 << endl;
}