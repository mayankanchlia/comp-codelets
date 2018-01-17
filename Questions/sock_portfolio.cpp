#include <iostream>
#include <algorithm>
#define ll unsigned long long
using namespace std;
ll table[1123456];
struct Job
{
    ll start, finish, profit;
};
bool myfunction(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}
ll binarySearch(Job jobs[], ll index)
{   
    ll lo = 1, hi = index;   
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
 
    return -1;
}
ll findMaxProfit(Job arr[], ll n)
{   
    sort(arr+1	, arr+n+1, myfunction);   
    table[1] = arr[1].profit;
    for (ll i=2; i<=n; i++)
-    {
        ll inclProf = arr[i].profit;
        ll l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i-1]);
    }
 
    
    ll result = table[n];
 
    return result;
}
int main (int argc, char ** argv){
	ios::sync_with_stdio(0);
	ll n;
	cin >> n;
   
	Job arr[n+1];
	for(ll i =1 ; i <= n ; i++){
		ll a;
		cin >> a;
		arr[i].profit = a;
	}
	for(ll i =1 ; i <= n ; i++){
		ll a;
		cin >> a;
		if(i-a >=1) arr[i].start = i-a;
		else arr[i].start =1;
	}
	for(ll i =1 ; i <= n ; i++){
		ll a;
		cin >> a;
		if(i+a <=n+1) arr[i].finish = i+a;
		else arr[i].finish =n+1;
	}
	if(n!=1){
	 cout << findMaxProfit(arr, n) <<endl;
    }
    else cout << arr[1].profit <<endl;
}