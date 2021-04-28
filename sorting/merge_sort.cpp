#include <iostream>
#include <vector> 
using namespace std;
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
// }; 
struct ListNode{
    int val; 
    ListNode *next;
    ListNode() : val(0), next(NULL){}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(int x, ListNode *next) : val(x), next(NULL){}
};
void findMid(ListNode * head, ListNode ** firstRef, ListNode**SecondRef){
    ListNode * slow = head;
    ListNode * fast = head->next;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    *firstRef = head;
    *SecondRef = slow->next;
    slow->next = NULL;
}
ListNode * merge(ListNode * first, ListNode *second){
    if (first == NULL) 
        return (second); 
    else if (second == NULL) 
        return (first);
    ListNode * curr;
    ListNode * root;
        if(first->val < second->val){
            root = first;
            root->next = merge(first->next,second);
        }else{
            // cout << second->val << " ";
            root = second;
            root->next = merge(first,second->next);
        }
        // curr->next = new ListNode();
        // cout << endl;
    // if (first!=NULL){
    //     curr->next = first; 
    // }
    // if (second!=NULL){
    //     curr->next = second; 
    // }
    return root;
}
void mergeSort(ListNode **headRef){
    ListNode *a, *b;
    ListNode * head = *headRef;
    if(head == NULL || head->next == NULL){
        return ;
    }
    findMid(head,&a,&b);
    // while(head!=NULL){
    //     cout << a->val << " ";
    //     head = head->next;
    // }
    // cout << endl;
    // while(a!=NULL){
    //     cout << a->val << " ";
    //     a = a->next;
    // }
    // cout << endl;
    // while(b!=NULL){
    //     cout << b->val << " ";
    //     b = b->next;
    // }
    // cout << endl;
    mergeSort(&a);
    mergeSort(&b);
    *headRef = merge(a,b);
    
    // cout << endl;
}
int main(int argc, char ** argv){    
    ListNode * root = NULL;
    int n ; cin >> n ;
    ListNode * curr = root;
    for(int i = 0 ; i < n ; i++){
        int a ; cin >> a;
        ListNode * temp = new ListNode(a);
        if(curr != NULL){
            curr->next = temp;
            curr = curr->next;
        }else{
            curr = temp;
            root = curr;
        }
    }
    mergeSort(&root);
    // curr = findMid(root);
    curr = root;
    while(curr != NULL){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}