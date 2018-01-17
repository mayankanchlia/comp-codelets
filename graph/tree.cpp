#include <iostream>
#include <queue>
using namespace std;
struct node{
	int data;
	node * left;
	node * right;
};
node * newNode(int data){
	node * temp = new node;
	temp->left = NULL;
	temp->right = NULL;
	temp->data = data;
	return temp;
}
struct node* insert(node * root, int data){
	if(root == NULL) return newNode(data);
	else if(data < root->data) {
		root->left = insert(root->left,data);
	}
	else{
		root->right = insert(root->right , data);
	}
	return root;
}
void pri(node * root){
	if(root == NULL)return;
	cout << root->data<< endl;
	pri(root->left);
	pri(root->right);
}
void Levelorder(node * root){
	if(root== NULL) return;
	queue<node *> q;
	q.push(root);
	int arr[5]= {0};
	while(1){
		int nodeCount = q.size();
		if(nodeCount==0)break;
		while(nodeCount!=0){
			node * temp = q.front();q.pop();
			cout << temp->data <<" " ;
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!= NULL ){
				q.push(temp->right);
			}
			nodeCount--;
		}
		cout << endl;
	}
}
void LevelorderReverse(node * root){
	if(root== NULL) return;
	queue<node *  > q;
	q.push(root);
	vector<vector<int> > v;
	while(1){
		int nodeCount = q.size();
		if(nodeCount==0) break;
		vector<int> temp;
		while(nodeCount>0){
			node * temp1  = q.front();q.pop();
			temp.push_back(temp1->data);
			if(temp1->left!= NULL){
				q.push(temp1->left);
			}
			if(temp1->right!= NULL){
				q.push(temp1->right);
			}
			nodeCount--;
		}
		v.push_back(temp);
	}


	for(int i =0 ; i< v.size();i++){
		if(i%2!=0){
			revese(v[i].begin(),v[i].end());
		}
	}
	return v;
	for(int i =v.size()-1 ; i>=0;i--){

		for(int j = v[i].size()-1 ; j>=0;j-- ){
			if(i)
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
nlc
int main (int argc ,char ** argv){
	int t ; cin >> t;
	while(t--){
		int n , m ;
		cin >> n >> m;
		node *root = newNode(1);
	    root->left = newNode(2);
	    root->right = newNode(3);
	    root->left->left = newNode(4);
	    root->left->right = newNode(5);
	    root->right->right = newNode(6);
		// for(int j =0 ; j < n ; j++){
		// 	int a ; cin >> a;
		// 	root = insert(root,a);
		// }
		LevelorderReverse(root);

	}



}