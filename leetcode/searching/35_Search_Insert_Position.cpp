#include<iostream>
using namespace std;
#define MAXNUM 11234
int searchInsert(int* nums, int numsSize, int target){
    int start  = 0, end = numsSize -1;
    while(start <= end){
        int middle = (start + end)/2;
        // cout << middle << endl;
        if(nums[middle] < target){
            start = middle +1;
        }
        else if(nums[middle] > target ){
            end = middle -1;
        }
        else return middle;
    }
    // cout << start << " "  << end << endl;
     if(end > 0 && nums[end] < target){
        return end +1;
    }
    if(start < numsSize && nums[start] > target){
        return start;
    }
    return start;
}
int main(int argc, char ** argv){
    int n ; 
    cin >> n ;
    while(n--){
        int a ; 
        int abc[MAXNUM];
        cin >> a; 
        for(int i = 0 ; i< a;i++){
            cin >> abc[i];
        }
        int target ; cin >> target;
        cout << searchInsert(abc,a,target) << endl;
    }
    return 0;
}