#include <bits/stdc++.h>
using namespace std;

struct node{
	struct node * left;
	struct node * right;
	int data ;
	int depth;
}

node * newNode(int data){
	node * ret;
	ret->right = NULL;
	ret->left = NULL;
	ret->data = data;
}
node * insert(node * root,int a , int b){

}
int main(){
	int n ;
	cin >> n;
	for (int i = 1 ;i<=n;i++){
		int a ,b;
		cin >> a >>n;
		node * temp;
		temp = newNode(i);
		if (a!=-1)	temp->left = newNode(a);
		if (b!=-1)	temp->right = newNode(b);

	}
}