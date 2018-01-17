#include <bits/stdc++.h>
using namespace std;
int func(int * aux ,int n ,int left ,int right){
    int max1  = aux[0] , max_all = 0;
    for(int i =1 ; i < n ; i++){
        if(aux[i-1]==aux[i]){
 
            max1+=aux[i];

        }
        else if(aux[i]>max1){
            max1 = aux[i];
        }
        else{
        	if(max1>max_all) max_all = max1;
        	max1=0;
        }
        if(max1>max_all) max_all = max1;
    }
    //cout << max1<<endl;
    return max_all;
}
int maximalRectangle(vector<vector<int> > &A) {
	//cout <<"dasdas" <<endl;
    int n = A.size() , m = A[0].size();
    //cout << n << " " << m <<endl;
    int aux[n];
    int max1 = INT_MIN, up = 0 , down = 0 , left= 0 , right = 0;
    for(left =0 ; left < m ; left++){
        for(int k =0 ; k < n ; k++)aux[k] = A[k][left];
        for(right = left+1 ; right < m ; right ++){
            for(int k =0 ; k < n ; k ++){
                 aux[k] += A[k][right];
            }
  
        	max1 = max(max1, func(aux,n,left,right));
        }        
    }
    return max1;
}
int main(int argc , char ** argv ){
	int n , m ;
	cin >> n >> m;
	vector<vector<int> > mat(n);
	for(int i =0 ; i < n ; i++) for(int j =0 ; j < m ; j++){
		int a ; cin >> a;
		mat[i].push_back(a);
	}
	cout << maximalRectangle(mat) << endl;

}