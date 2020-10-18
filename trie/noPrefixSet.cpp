#include<iostream>
#include<string>
using namespace std;
const int alphabetSize = 10;
struct TrieNode {
    struct TrieNode * children[alphabetSize];
    bool endOfWord;
    int noOfwords;
};
struct TrieNode * root;
struct TrieNode * getNode(){
    struct TrieNode * temp = new TrieNode;
    for(int i =0 ; i < alphabetSize ; i++){
        temp->children[i] = NULL;
    }
    temp->noOfwords = 0;
    temp->endOfWord = false;
    return temp;
}
bool insertNode(string word){
    
    struct TrieNode * temp = root;
    // cout << word << endl;
    temp->noOfwords++;
    for(int i = 0 ; i< word.length() ; i++){
        int index = word[i] - 'a';
        // cout << index << endl;
        if (temp->endOfWord){
            cout << "BAD SET" << endl;
            cout << word << endl;
            return false;
        }
        if(temp->children[index] == NULL){
            temp->children[index] = getNode();
        }
        temp->noOfwords++;
        temp = temp->children[index];
    }
    if(temp->endOfWord || temp->noOfwords >= 1){
        cout << "BAD SET" << endl;
        cout << word << endl;
        return false;
    }
    temp->endOfWord = true;
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t ; cin >> t;
    bool ans = true;
    root = getNode();
    while(t--){
        string word; cin >> word;
        if(ans){
            ans = insertNode(word);
        }
    }
    if(ans){
        cout << "GOOD SET" << endl;
    }
    return 0;
}
