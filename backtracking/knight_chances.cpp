#include<stdio.h>
#define N 8 
bool isValid (int x , int y , int sol[N][N]){
	if(sol[x][y] == -1 && x >=0 && x<N && y >=0 && y <N) return true;
	else return false;
}	
bool move_next(int x, int y , int num , int sol[N][N]){
	if (num == 64) return true ;
	int i , next_y , next_x;
	int move_x[8]={2,1,-1,-2,-2,-1,1,2};
	int move_y[8]={1,2,2,1,-1,-2,-2,-1};
	for ( i = 0 ; i < N ;i ++){
		next_x = x + move_x[i];	
		next_y = y + move_y[i];
		if(isValid(next_x, next_y , sol)==true){
			sol[next_x][next_y] = num;
			
		 	if(move_next(next_x,next_y,num+1,sol)==true){
		 		printf("second\n");
		 		return true ;
		 	}
			else{
		 		sol[next_x][next_y]=-1;
			}
		}

	}
	return false;

}


int main(int argv , char** argc){	
	int sol[N][N];
	for (int i = 0 ; i<N; i++ ){
		for (int j =0 ; j <N;j++) sol[i][j]=-1;
	}
	sol[0][0]=0;
	printf("first\n");
	move_next(0,0,1,sol);

	for (int i = 0 ; i<N; i++ ){
		for (int j =0 ; j <N;j++){

			printf("%2d ",sol[i][j]) ;
		}
		printf("\n");
	}
	
}