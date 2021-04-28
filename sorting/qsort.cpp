#include <iostream> 
using namespace std;
void swap(int * arr, int i , int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int partition(int * arr1, int * arr2, int l , int r){
	int pivot = r;
	int i = l;
	for(int j = l; j < r ; j++){
		if(arr1[j] < arr1[pivot]){
			swap(arr1,i,j);
			swap(arr2,i,j);
			i++;
		}
	}
	swap(arr1,i,pivot);
	swap(arr2,i,pivot);
	return i;
}
void qsort(int * arr1, int * arr2, int l, int r){
	if(l < r){
		int p = partition(arr1,arr2,l,r);
		qsort(arr1, arr2, l,p-1);
		qsort(arr1, arr2, p+1,r);
	}
}
int main(int argc, char ** argv){
	int n ; cin >> n ;
	int arr[n]; 
	for(int i =0 ; i < n ; i++)cin >> arr[i] ;
	int subArr[n];
	for(int i = 0 ; i< n ; i++) cin >> subArr[i];
	qsort(arr,subArr,0,n-1);
	for(int i = 0 ; i< n ; i++) cout << arr[i] << " " ;
	cout << endl;
	for(int i = 0 ; i< n ; i++) cout << subArr[i] << " " ;
	cout << endl;
}