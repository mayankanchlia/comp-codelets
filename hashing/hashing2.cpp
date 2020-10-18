#include<iostream>
using namespace std;
const int MAX_WIDTH = 112345;
struct Node {
    int data;
    struct Node * next;
};
struct nodeChain{
    struct Node *first;
    struct Node *last;
};
struct Node * getNode(){
    struct Node * temp = new Node;
    temp->data = 0;
    temp->next = NULL;
    return temp;
}
struct nodeChain * arr[MAX_WIDTH];
struct nodeChain * getNodeChain(){
    struct  nodeChain * temp = new nodeChain;
    temp->first = NULL;
    temp->last = NULL;
    return temp;
}
void initNodeChain(){
    for(int i =0 ; i < MAX_WIDTH ; i++){
        arr[i] = getNodeChain();
    }
} 
int hashFunct(char * word){
    return 1 ;
}
char* table[MAX_WIDTH];
int cnt = 0;
int main(int argc , char ** argv){
    int test ; cin >> test;
    cout << test << endl;
    initNodeChain();
    for(int t = 0 ; t < test ; t++){
        char  * str1 = new char[1024]; cin >> str1;
        table[cnt] = str1;
        int has = hashFunct(str1);
        struct Node *temp = getNode();
        temp->data = cnt++;
        temp->next = NULL;
        if(arr[has]->first == NULL){
            arr[has]->first = temp;
            arr[has]->last = temp;
        }
         else{
            cout << "yolo " << arr[has]->last->data << endl;
            arr[has]->last->next = temp;
            arr[has]->last = temp;
        }
    }
    struct Node *temp = arr[1]->first;
    while(temp != NULL){
        cout << temp->data << " " << table[temp->data] <<  endl;
        temp = temp->next;
    }
}