#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map<char,int> a1;
    vector<int> arr(A.length());
    arr[0]=1;
    a1.insert(make_pair(A[0],0));
    for(int i = 1 ; i < A.length();i++){
        if(a1.find(A[i])==a1.end()){
            a1.insert(make_pair(A[i],i));
            arr[i] = arr[i-1]+1;
        }
        else{
            cout << A[i] << " " << a1[A[i]] << " " << i << endl;
            arr[i] = i-a1[A[i]];
            a1[A[i]] = i;
        }
        for(int k =0 ; k<=i;k++){
        cout << arr[k] << " ";
        }
        cout << endl;
        //if(max<arr[k]) max = arr[i];
    }
    int max = 0;
    for(int i =0 ; i< A.length();i++){
        cout << arr[i] << " ";
        if(max<arr[i]) max = arr[i];
    }
    cout << endl;
    return max;
    
}
int main(int argc ,char ** argv){
    string s;cin >> s;
    lengthOfLongestSubstring(s);

}
