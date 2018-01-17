#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
long int count( int S[], int m, int n )
{
    long int i, j, x, y;
    long int table[n+1][m];
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
           table[i][j] = x + y;
           // cout <<i<<" "<<j<<" "<<  table[i][j]<<endl;
        }
    }
    
    return table[n][m-1];
}
 
// Driver program to test above function
int main()
{
    int n , m ;
    cin >> n >>m;
    int arr[m];
    for(int i =0 ;i<m;i++) cin >> arr[i]; 
    cout << count(arr, m, n);
    return 0;
}