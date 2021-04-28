#include <bits/stdc++.h>
using namespace std;
int maximumGap(vector<int>& nums) {
    int size = nums.size();
    if(nums.size()<2) return 0;
    int min_val = INT_MAX, max_val=INT_MIN; 
    for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] < min_val){
            min_val = nums[i];
        }
        if(nums[i] > max_val){
            max_val = nums[i];
        }
    }
    int range = max_val - min_val +1;
    // cout << min << " " << max << endl;
    int diff = (range)/(nums.size() -1);
    vector<int> maxElement(size,INT_MIN);
    vector<int> minElement(size,INT_MAX);
    for(int i = 0 ; i < size; i++){
        int index = (nums[i] - min_val)/diff;
        maxElement[index] = max(maxElement[index], nums[i]);
        minElement[index] = min(minElement[index], nums[i]);
    }
    for(int i = 0 ; i < size; i++){
        cout << maxElement[i] << " ";
    }
    cout << endl;
    for(int i = 0 ; i < size; i++){
        cout << minElement[i] << " ";
    }
    cout << endl;
    int max_gap = INT_MIN;
    int last_min = min_val;
    for(int i =0 ; i < size ; i++){
        if(maxElement[i]!= INT_MIN){
           max_gap = max(max_gap,maxElement[i]- last_min); 
           last_min = minElement[i];
        }
    }
    return max_gap;

}
int main (int argc, char ** argv){
    int n ; cin >> n ; 
    vector<int> arr;
    for(int i = 0 ; i< n ; i++){
        int a ; cin >> a;
        arr.push_back(a);
    }
    for(int i = 0 ; i< n ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
   cout <<  maximumGap(arr) << endl;
}  

