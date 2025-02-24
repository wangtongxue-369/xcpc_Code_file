#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, k, a[N], f[N];
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll maxn = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        maxn = max(maxn, a[i]);
    }
    ll zs;
    for (int i = n; i >= 1; i--)
    {
        zs = (sum + k) / i;
        // zushu
        if (zs < maxn)
        {
            continue;
        }
        if (zs * i < sum)
        {
            continue;
        }
        cout << i << '\n';
        return;
    }
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
