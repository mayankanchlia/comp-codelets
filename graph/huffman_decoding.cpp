#include <bits/stdc++.h>
using namespace std;

struct node {
	int freq;
	struct node * left;
	struct node * right;
	int data;
};
node * insert(node * root, int a,int b,int i){
	if(root == NULL){
		return newNode(data);
	}
	while(i--){
		
			root->left = insert(root->left,data);
		
		
			root->right = insert(root->right,data);
		
	}
	return root;
}
void In
void decode_huff(node* root,string s){
	for(int i = 0 ; i < s.len() ; i++){}
		if(root->left)
		if(s[i]==0){
			root = root->left
		}
		else if (s[i] == 1){
			root = root->right;
		}
		if(root->left==NULL || root->right==NULL){
			cout << root-<data;
		}

}

int main(){

}