#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node * left ;
	node * right ;
};
node * newNode(int data){
	node * temp = new node;
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
void diagonalTravesal( node * root){
	map<int,vector<int> > a1;
	queue<pair<int,node *> > q;
	if(root == NULL) return;
	q.push(make_pair(0,root));
	while(!q.empty()){
		pair<int,node * > temp = q.front();q.pop();
		a1[temp.first].push_back(temp.second->data);
		//node * a = temp.second;
		//cout << temp.second->data << " ";
		if(temp.second->left!=NULL){
			q.push(make_pair(temp.first+1,temp.second->left));
		}
		if(temp.second->right !=NULL){
			q.push(make_pair(temp.first,temp.second->right));
		}
	}
	map<int , vector<int> >::iterator itr;
	for(itr=a1.begin();itr!= a1.end();itr++){
		for(auto it =itr->second.begin() ; it!= itr->second.end();it++){
			cout << *it << " ";
		}
		cout << endl;
	}
}
int main(int argc, char ** argv){
	node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
    diagonalTravesal(root);
}