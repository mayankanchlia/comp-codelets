#include <iostream>
using namespace std;
struct trieNode {
	struct trieNode *childen[2];
	bool endOfDigit;
};
struct trieNode* newNode(){

	trieNode *pNode  = new trieNode;

	pNode->endOfDigit = false;
	pNode->childen[0] = NULL;
	pNode->childen[1] = NULL;

	return pNode;
}
void insert(trieNode *root , int digit){
	trieNode *pNode = root;
	int digit_copy = digit;
	for(int i =31 ; i >= 0  ; i--){
		int a = (digit_copy >> i) &  1 ; 
		//cout << a ;
		if(!pNode->childen[a]){
			pNode->childen[a] = newNode();
		}
		pNode = pNode->childen[a];

	} 
}

int main(int argc, char ** argv){
 	
	int  a = 16;

	trieNode *node1 = newNode();
	
	insert(node1,a);
	insert(node1,5);
	insert(node1,6);
	insert(node1,10);
	w
	cout << endl;
	while(node1){
		if(node1->childen[0]){
			node1 = node1->childen[0];
			cout << "0";
		}
		else if (node1->childen[1]){
			node1 = node1->childen[1];	
			cout << "1";
		}
		else {
			node1 = NULL;
		}	
	}
return 0;
}