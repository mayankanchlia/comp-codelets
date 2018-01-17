#include <stdio.h>
int min ( int x, int y){
	if(x<=y) return x;
	else return y;
}
bool isValid(int ** mat , int n , int row, int col ){
	for (int i = col ; i >=0 ; i--){
		if(mat[row][i] ==1) return false;
	}
	for(int i = row ; i >=0 ; i--){
		if(mat[i][col]==1) return false;
	}
	//int i ,j;
	for (int i = row , j =col ;i>=0&&j>=0 ; i--,j--){
		if(mat[i][j]==1) return false;
	}
	for (int i = row , j =col ;i<n&&j>=0 ; i++,j--){
		if(mat[i][j]==1) return false;
	}
	printf("%d , %d \n",row,col);
	for (int i = row , j =col ;i>=0 && j<n ; i--,j++){
		if(mat[i][j]==1){
			printf("%d, %d",i,j);
		 return false;
		}
	}
    //for (int i=row, j=col; j>=0 && i<n; i++, j--)
      //  if (mat[i][j])  return false;

	return  true ;

}
void clear(int **mat, int n ){
		for (int i =0 ; i <n ; i++){
			for ( int j = 0 ; j < n ; j++){
				mat[i][j] = 0 ;
			}
		}
}
bool func(int ** mat,int n,int col){
	if (col >=n ) return true;
		for ( int i = 0 ; i <n ; i++){
			
				if(isValid(mat,n,i,col)){
					mat[i][col]=1;
					if(func(mat,n,col+1)){
						return true;
					}
					else {
						mat[i][col]=0;
					}
				}		 

		}
	return false;
}	
int main (int argc , char ** argv){
	int t ; 
	scanf("%d",&t);
	for (int m = 0 ; m < t;m++){
		int ** mat;
		int n ;
		scanf("%d",&n);
		mat = new int *[n];
		for(int i = 0 ; i <n ; i++){
			mat[i] = new int[n];
		}
		int count = 0 ;
		
		for (int i =0 ; i <n ; i++){
			for ( int j = 0 ; j < n ; j++){
				mat[i][j] = 0 ;
			}
		}
		
		func(mat,n,0); 
		//printf("asdad\n");
		for (int i =0 ; i <n ; i++){
			for ( int j = 0 ; j < n ; j++){
				printf("%2d",mat[i][j]);
			}
			printf("\n");
		}
	}
	return 0;

}