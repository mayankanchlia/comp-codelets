#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int alphabetSize = 26;
struct TrieNode {
    struct TrieNode *children[alphabetSize];
    int endOfWord ;
    bool winning;
    vector<int> wordLengthRemaining;    
};
struct TrieNode * root;
struct TrieNode * getNode(){
    struct TrieNode * temp = new TrieNode;
    for(int i = 0 ; i<alphabetSize ; i++){
        temp->children[i] = NULL;
    }
    temp->endOfWord = false;
    return temp;
}
void insertNode(string word){
    struct TrieNode * temp = root;
    for(int i = 0 ; i < word.length(); i++){
        int index = word[i] - 'a';
        if(!temp->children[index]){
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
    temp->endOfWord = true;
}
struct TrieNode * queue[112345];
int cnt = 0;
void func(struct TrieNode * root , int ){
    struct TrieNode * temp = root;
    int co = 0;
    while(temp && co <= cnt){
        co++;
        for(int i = 0 ; i< alphabetSize ; i++){
            if(temp->children[i]){
                queue[cnt++] = temp->children[i];
            }
        }
        temp = temp->children[co];
    }
}

int main(int argc , char ** argv){
    int n , k ; 
    cin >> n >> k;
    for(int i =0 ; i < n ; i++){
        string a; 
    }
}