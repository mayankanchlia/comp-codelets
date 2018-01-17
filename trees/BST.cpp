#include <bits/stdc++.h>

using namespace std;

struct node {
	struct node * left ;
	struct node * right;
	int data ;
};

struct node * newNode(int data){
	node * ret = new(node);
	ret->left = NULL;
	ret->right = NULL;
	ret->data = data;
	return ret;
}

node * insert(node * root, int data){
	if(root == NULL){
		return newNode(data);
	}
	if(root->data > data){
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right,data);
	}
	return root;
}
void Inorder(node * root){
	if(!root) return;
	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}
void PreOrder(node * root){
	if(!root) return;
	cout << root->data << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}
void PostOrder(node * root){
	if(!root) return;
	
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}
void levelOrder(node * root){
	if(!root) return;
	queue<node* > q;
	q.push(root);
	while(!q.empty()){
		node * temp;
		temp = q.front();
		q.pop();
		cout << temp->data  << " ";
		if(temp->left != NULL){
			q.push(temp->left);
		}
		if (temp->right != NULL){
			q.push(temp->right);

		}
	}

}




int main(){
	int root , n , temp;
	cin >> n;
	cin >> root;
	node * node1 ;
	node1 = newNode(root);
	for (int i = 0 ; i <n ; i++){
		cin>>temp;
		insert(node1,temp);
	}
	Inorder(node1);
	cout << endl;
	PreOrder(node1);
	cout << endl;
	PostOrder(node1);
	cout << endl;
	levelOrder(node1);
}