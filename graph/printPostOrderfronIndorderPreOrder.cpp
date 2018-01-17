#include <iostream>
using namespace std;
int root(int * inOrder,int start , int end, int key){
	if(start > end) return -1;
	int mid = (start+end)/2;
	if(inOrder[mid]>key) roo(inorder, start,end-1);
	if(inOrder[mid]<key) roo(inorder, mid+1,end);
	if(inorder[mid]==key) return key;
	return -1;
}
void postOrder(int * inOrder, int* preOrder,int n , int m){
	int r = root(inOrder,preOrder)
}
int main(int argc, char ** argv){
	int n , m ;
	int inorder[n];
	int preOrder[n];
	for(int i =0 ; i< n ; i++) cin >> inorder[i];
	for(int i =0 ; i < n ; i++) cin>> preOrder[i];
}