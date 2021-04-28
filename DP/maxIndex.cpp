#include <bits/stdc++.h>
using namespace std;
int steps, badIndex;
int maxIndex(int step, int curr){
    if(step == steps+1) return curr;
    if(curr == badIndex) return INT_MIN;
    return max(maxIndex(step+1,curr+step), maxIndex(step+1,curr) );
}
int main(int argc, char ** argv){
    cin >> steps >> badIndex ;
    cout << steps << " " << badIndex << endl;
    cout << maxIndex(1,0) << endl;
    vector<int> arr(steps);
    for(int i =0 ; i < steps; i++)
    return 0;
}