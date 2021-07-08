#include<iostream> 
#include<vector>
#include<algorithm>
using namespace std;
int binarySearch_iterative(vector<int> arr, int x){
    if(x < arr[0])return 0;
    if(x > arr[arr.size()-1]) return arr.size()-1;
    int start = 0, end = arr.size()-1;
    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]< x){
            if(mid +1 < arr.size() && x < arr[mid+1]){
                if(arr[mid+1] - x < x- arr[mid] ) return mid+1;
                else return mid;
            }
            start = mid+1;
        }else if (arr[mid] > x) {
            if(mid -1 >=0  && x > arr[mid-1]){
                if(arr[mid] - x < x- arr[mid -1] ) return mid;
                else return mid-1;
            }
            end = mid -1;
        }
    }
    return -1;
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int closest = binarySearch_iterative(arr, x);
        int left  = closest -1 , right = closest+1;
        vector<int> ans(k);
        k--;
        ans[k--] = arr[closest];
        // cout << closest << endl; 
        while(left >= 0 && right < n && k>=0){
           if(abs(arr[left] - x ) <= abs(arr[right] - x)){
               ans[k--] = arr[left--];
           }else{
               ans[k--] = arr[right++];
           }
       }
       while(left >= 0  && k>=0){
           ans[k--] = arr[left--];
       }
       while(right < n && k>=0){
            ans[k--] = arr[right++];
       }
        sort(ans.begin(), ans.end());
        return ans;
    }
// find k closest can be changed to find a i such that 
// arr[i] ~ arr[i+k-1] is closest to x 
vector<int> findClosestElements_concise(vector<int> & arr, int k , int x){
    int left = 0, right = arr.size() -k;
    while(left < right){
        int mid = (left + right)/2;
        if(x- arr[mid] > arr[mid+k] -x){
            left = mid+1;
        }
        else {
            right = mid -1;
        }
    }
    cout << left << endl;
    return vector<int>(arr.begin()+left,arr.begin()+left + k );
    }
int main(int argc, char ** argv){
    int t ; cin >> t ;
    while(t--){
        int n , x, k; cin >> n >> x >> k;
        vector<int> arr(n);
        for(int i =0 ; i< n ; i++)cin >> arr[i];
       vector<int> ans = findClosestElements_concise(arr, k,x);
       for(auto& a : ans) cout << a << " ";
       cout << endl;
    //    int left  = closest -1 , right = closest+1;
    }
    return 0;
}