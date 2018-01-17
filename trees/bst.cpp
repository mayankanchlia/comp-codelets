#include <bits/stdc++.h>
using namespace std;
int arr1[100];
int arr2[100];
int sorted[600];
struct node{
	int data;
	struct node* left;
	struct node* right;
}; // C++ does away with typedef. Don't have to type struct node* everywhere.

int search(node* root, int target){
	//Base Case: Empty tree. Target not found
	if (!root){ //equivalent to root == NULL
		return 0;
	}

	if (root->data == target){
		return 1;
	}
	else{
		if(target < root->data) // BST Property
			return search(root->left,target);
		else
			return search(root->right,target);
	}
}

node* newNode(int data){
	node* ret = new(node); //equivalent to malloc(sizeof(node))
	ret->data = data;
	ret->left = NULL;
	ret->right = NULL;

	return ret;
}

node* insert(node* root, int data){
	if(!root)
		return newNode(data);

	if (data <= root->data){
		root->left = insert(root->left,data);
}
	else
		root->right = insert(root->right,data);

	return root;
}

void display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
        }
        cout<<ptr->data;
        display(ptr->left, level+1);
    }
}
void inorder(node *ptr,int* arr,int *j ){
    if (ptr != NULL)
        {

         inorder(ptr->left,arr,j);
         //cout<<ptr->data;
         arr[*j] = ptr->data;
         (*j)++;
         inorder(ptr->right,arr,j);

    }
}
void inorder1(node *root){
    if (!root) return;
    inorder1(root->left);
    cout << root->data << " ";
    inorder1(root->right);
}

/*
void maxDepth(node *ptr){
    while(ptr->left != NULL){
        hieghtLe++;
    }
    while(ptr->right != NULL){
        hieght++;sorted
    }
}
*/
/*
Implement
0) main() to create BSTs manually (called the driver function)
1) traversals: inorder, preorder, postorder, level order
2) function to check if given BST is root node. Hint: I can create an invalid BST just by using newNode function.
3) maxDepth, minDepth
4) minElement, maxElement of subtree
5) inorder successor, predecessor (look at cormen for edge cases)
6) LCA of two nodes
7) Delete BST (every node should be removed without dangling references). Use the delete keyword.
*/
void mergeArray(int * arr1 , int * arr2 , int * newArray,int n ){
  int  i =0 , j = 0, k =0;
    while(i<n && j<n){
        if( arr1[i]<arr2[j]  )  {
         newArray[k] = arr1[i];
         i++;
        }
        else if (arr1[i]>= arr2[j] ){
         newArray[k] = arr2[j];
         j++;
     }
     k++;
    }
    while (i < n)
    {
        newArray[k] = arr1[i];
        i++; k++;
    }
 
    // If there are more elements in second array
    while (j < n)
    {
        newArray[k] = arr2[j];
        j++; k++;
    }
}
node * SortedArrayToBSt(int start, int end){
    if(start > end) return NULL;
    int mid = (start+end)/2;
    node * root = newNode(sorted[mid]);
    root->left = SortedArrayToBSt(start,mid-1);
    root->right = SortedArrayToBSt(mid+1,end);
    return root;

}
node* SortedArraytoBalancedBST(int start,int end)
{
    if(start > end) return  NULL;
    int mid=(start+end)/2;
    node * root = newNode(sorted[mid]);
    root->left = SortedArraytoBalancedBST(start,mid-1);
    root->right = SortedArraytoBalancedBST(mid+1,end);
    return root;
}
int main(){
    int root,root2,n,temp;
    cin>> n ;
    cin >> root;
    cin >> root2;
    node* node1;
    node* node2;
    node1 = newNode(root);
    node2 = newNode(root2);
    for (int i = 0 ; i < n-1 ;i++){
        cin>>temp;
        //cout << "temp " << temp <<" ";
        insert(node1,temp);
    }
    for (int i = 0 ; i <n-1 ;i++){
        cin>>temp;
        insert(node2,temp);
    }
    //inorder1(node2);
    //cout << endl;
    //display(node1,3);
    //display(node2,3);
    int j = 0;
    inorder(node1,arr1, &j);
    // for ( int i = 0 ; i <n;i++){
    //     cout << arr1[i];
    // }
    // cout <<endl;
    j = 0;
    inorder(node2,arr2, &j);
    // for ( int i = 0 ; i <n;i++){
    //     cout << arr2[i];
    // }
    // cout << endl;   
    mergeArray(arr1,arr2,sorted,n);

    // for (int i = 0 ; i <2*n ; i++){
    //     cout << sorted[i] << " ";
    // }
    //cout << endl;
    node * node3;
    // node3 = SortedArrayToBSt(0,n+n-1);
    node3 = SortedArrayToBSt(0,n+n-1);
    inorder1(node3);
    // node * new1;
    // for (int i = 0 ; i <n+n ;i++){
    //     insert(new1,sorted[i]);
    // }

   // cout << node1->data << node1->left->data << node1->right->data << endl;

	return 0;
}
