#include<iostream>
#include<vector>
using namespace std;
void swap(int & a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void partition(vector<int> &nums, int l , int r, int &i , int & j ){
    if(r-l <=1){
        if(nums[r] < nums[l])swap(nums[r],nums[l]);
        i = l ; 
        j = r;
    }
    int low = l;
    int mid = l; 
    int high = r;
    int pivot = nums[r];
    while(mid <= high){
        if(nums[mid] < pivot){
            swap(nums[mid], nums[low]);
            low++;mid++;
        }else if(nums[mid] == pivot){
            mid++;
        }else if (nums[mid] > pivot){            
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    i = low -1;
    j = mid;

}
void q_sort(vector<int> &arr,int l , int r ){
    if(l <r){
        int i , j;
        partition(arr, l , r , i, j);
        q_sort(arr,l, i);
        q_sort(arr,j, r);
    }
}
int main(int argc , char ** argv){
    int n ; cin >> n ;
    vector<int> nums(n);
    for(int i =0 ; i < n ; i++){
        int a ; cin >> a; 
        nums[i] = a;
    }
    int i = -1, j = -1;
    q_sort(nums,0, n-1 );
}