#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the contacts function below.
 */
const int alphabetSize = 26;
struct TrieNode {
  bool endOfWord;
  struct TrieNode *children[alphabetSize];
  int noOfword;
};
struct TrieNode *root;
int countWord = 0;
struct TrieNode *getNode() {
  struct TrieNode *temp = new TrieNode;
  temp->endOfWord = false;
  temp->noOfword = 0;
  for (int i = 0; i < alphabetSize; i++) {
    temp->children[i] = NULL;
  }
  return temp;
}
void insertWord(string word) {
  struct TrieNode *temp = root;
  temp->noOfword++;
  for (int i = 0; i < word.length(); i++) {
    int index = word[i] - 'a';
    if (temp->children[index] == NULL) {
      temp->children[index] = getNode();
    }
    temp = temp->children[index];
    temp->noOfword++;
  }
  temp->endOfWord = true;
}
int searchWord(string prefix) {
  struct TrieNode *temp = root;
  for (int i = 0; i < prefix.length(); i++) {
    int index = prefix[i] - 'a';
    if (temp->children[index] == NULL) {
      return 0;
    }
    temp = temp->children[index];
  }
  return temp->noOfword;
}
vector<int> contacts(vector<vector<string>> queries) {
  vector<int> result;
  root = getNode();
  for (int i = 0; i < queries.size(); i++) {
    if (queries[i][0] == "add") {
      insertWord(queries[i][1]);
    } else if (queries[i][0] == "find") {
      result.push_back(searchWord(queries[i][1]));
    }
  }
  for(int i =0 ; i< result.size(); i++){
      cout << result[i] << endl;
  }
  return result;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  int queries_rows;
  cin >> queries_rows;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  vector<vector<string>> queries(queries_rows);
  for (int queries_row_itr = 0; queries_row_itr < queries_rows;
       queries_row_itr++) {
    queries[queries_row_itr].resize(2);

    for (int queries_column_itr = 0; queries_column_itr < 2;
         queries_column_itr++) {
      cin >> queries[queries_row_itr][queries_column_itr];
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
  }

  vector<int> result = contacts(queries);

  for (int result_itr = 0; result_itr < result.size(); result_itr++) {
    fout << result[result_itr];

    if (result_itr != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";

  fout.close();

  return 0;
}
