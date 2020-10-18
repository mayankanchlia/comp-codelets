#include <iostream>
#define ll long long
using namespace std;
ll mod = 1000000007;
int v[1000005];
int N = 1000000;
ll solve(ll lf, ll rg)
{
    if (lf == rg)
    {
        return v[lf];
    }
    ll m = (lf + rg) >> 1;
    ll l = solve(lf, m);
    ll r = solve(m + 1, rg);
    return (l + r + l * r) % mod;
}

int main()
{

    for (int i = 1; i <= N; i++)
    {
        v[i] = i;
    }
    int t;
    cin >> t;
    for (int t1 = 0; t1 < t; t1++)
    {
        int n;
        cin >> n;
        cout << solve(1, n) << endl;
    }
}