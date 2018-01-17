#include <stdio.h>

bool validmove(int x, int y , int	sol[4][4],int N){
	//printf("first\n");
	if(sol[x][y]==1) return true;
	else return false;
}
bool solve(int x , int y , int	sol[4][4], int N){
	if(x == N-1 && y == N-1) return true;
	
	int next_x, next_y;
	for(int i = 0 ; i < 9 ; i++){
		next_x = x+1;
		next_y = y+1;
		if(validmove(next_x,y,sol,N)==true){
			sol[next_x][y]=9;

			if(solve(next_x,y,sol,N)==true) return true;
			else sol[next_x][y]=1;
		}
		else if(validmove(x,next_y,sol,N)==true){
			sol[x][next_y]=9;
			if(solve(x,next_y,sol,N)) return true;
			else sol[x][next_y] = 1;
		}
	}
	return false;
}
int main (int argc , char ** argv){
	int N,temp;
	scanf("%d",&N);
	printf("%d\n",N );
	int mat[4][4];
	for(int i = 0 ; i <N ;i++){
		for(int j = 0 ; j < N ; j++){
			scanf("%d",&temp);
			mat[i][j] = temp;
		}
	}
		for(int i = 0 ; i <N ;i++){
			for(int j = 0 ; j < N ; j++){
			printf("%d ",mat[i][j]);
			//max[i][j] = temp;
		}
		printf("\n");
	}
	solve(0,0,mat,N);

			for(int i = 0 ; i <N ;i++){
				for(int j = 0 ; j < N ; j++){
				printf("%d ",mat[i][j]);
			//max[i][j] = temp;
			}
		printf("\n");
	}

}