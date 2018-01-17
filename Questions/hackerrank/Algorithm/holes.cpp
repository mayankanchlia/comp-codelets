#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a , int *b){
	int temp;
	temp = *a;
	*a= *b;
	*b = temp;
}

int main (){
	std::ios::sync_with_stdio(false);
	int n,m,k,first,second;
	cin >>n>>m>>k;
	int arr[n+1]={0};
	int bone;
	for (int i = 1;i<=m;i++){
		int j;
		cin>>j;
		arr[j]=2;
	}
	if(arr[1]!=2) arr[1]=1;
	else bone = 1;
	// for(int i =1;i<=n;i++) cout<< arr[i];
	// 	cout <<endl;

	if(arr[1]!=2){
	for(int i=1;i<=k;i++){
		cin>>first>>second;
		if(arr[first] !=2 && arr[second]!=2){
			swap(&arr[first],&arr[second]);
			if(arr[first]==1) bone = first;
			else if (arr[second]==1) bone = second;
			//cout<<"no"<<bone;

		}
		else if(arr[first]==2){
			if(arr[second]==1){
				bone = first;
			//	cout<<"first"<<bone;
				break;

			}

		}
		else if ( arr[second]==2){
			if(arr[first]==1){
				bone = second;
			//	cout << "second"<<bone;
				break;

			}
		}
	}
	cout << bone<<endl;
	}
	else cout<<1;
	// for(int i =1;i<=n;i++) cout<< arr[i];
	// 	cout <<endl;
	return 0;

}