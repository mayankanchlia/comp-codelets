#include <iostream>
using namespace std;
int arr1[11234];
int arr2[11234];

int partition(int l , int r){
	int pivot = arr1[1];
	
}
void qsort(int l ,int r){

	if(l<r){
		int p = partition(l,r);
		qsort(l,p-1);
		qsort(p+1,r);
	}
}
int main(int argc , char ** argv){
	int  n ; cin >> n;
	for(int i = 0  ;i < n ;i++) cin >> arr[i];

}