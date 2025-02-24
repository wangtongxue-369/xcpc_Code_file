#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];

void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // sort(a+1,a+1+n);
    for (int i = 1; i < n - 1; i++)
    {
        a[n - 1] -= a[i];
    }
    cout << a[n] - a[n - 1] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
