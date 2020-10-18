#include <iostream>
#include <vector>
#include <string>
#include <queue> 
#include <unordered_map>

using namespace std;

const int MAX_SIZE = 112345;
class Compare{
    public:
        bool operator() (pair<string, int> a, pair<string, int> b)
        {
            if(a.second != b.second){
                return a.second < b.second;
            }else{
                return a.first > b.first;
            }
        }
};

vector<string> solve(vector<string> words, int k){
    vector<string> res;
    unordered_map<string, int> um;
    for(int i=0; i<words.size(); i++){
        if(um.find(words[i]) != um.end()){
            um[words[i]]++;
        } else{
            um.insert(make_pair(words[i], 1));
        }
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    unordered_map<string, int>::iterator iter;
    for(iter = um.begin(); iter!=um.end(); iter++){
        pq.push(make_pair(iter->first, iter->second));
    }

    for(int i=0; i<k; i++){
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<string> arr;
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int k;
    cin >> k;

    vector<string> res = solve(arr, k);
    for (int i=0; i<k && i<res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
