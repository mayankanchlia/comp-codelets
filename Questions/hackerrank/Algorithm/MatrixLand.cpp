#include <iostream>
using namespace std;
int n , m,pt,gmax;
int graph[1123][1123];
int x_move[3] = {0,0,1};
int y_move[3] = {-1,1,0};
int visited[1123][1123];
int DP[1123][1123];
bool isSafe(int x , int y){
	return x>=0 && x<n && y >=0 && y < m && visited[x][y] <=1;
}
int func(int x, int y){
	if(DP[x][y]==0){
		if(x==n-1){
			int b = pt;
			pt+=graph[x][y];
			int a = pt;
			for(int i = y+1 ; i<m;i++){
				pt+=graph[x][i];
				if(pt>a) a= pt;
			}
			for(int i = y-1 ; i>=0;i--){
				pt+=graph[x][i];
				if(pt>a) a=pt;
			}
			if(gmax<a) {
				//cout <<y <<endl;
				gmax= a;
				DP[x][y]=a;
			}
			pt = b;
		}
		else{
			for(int i = 0 ; i< 3 ;i++){
					int x_next=  x + x_move[i];
					int y_next = y + y_move[i];
					if(isSafe(x_next,y_next)){
						int a = graph[x_next][y_next];
						visited[x_next][y_next]++;
						pt+=a;
						graph[x_next][y_next] = 0;
						int g = func(x_next,y_next);
						if(g>DP[x_next][y_next]) DP[x_next][y_next] = g;
						graph[x_next][y_next] =a;
						visited[x_next][y_next]--;
						pt-=a;
					}
				}
		}
	}
	return  DP[x][y];
}
int main (int argc,char **argv){
	cin >> n >> m;
	for(int i =0 ; i< n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> graph[i][j];
		}
	}
	gmax=-1;
	//pt =1;
	
	int ggmax=0;

	for(int i =0 ; i < m ;i++){
		
		visited[0][i]++;
		for(int j = 0 ; j< n; j++){
			for(int k = 0; k < m ;k++){
				DP[j][k]=0;
			}
		}
		cout << func(i,0)<<endl;
		if(ggmax< gmax) ggmax =gmax;
		visited[0][i]--;	
	}
	cout << ggmax << endl;
	
}