#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[850][850], f[850][850];
ll k, zw;
bool check(ll x)
{
    // cout << "dang " << x << '\n';
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + (a[i][j] <= x ? 1 : 0);
        }
    }
    ll x1, y1, s;
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= n; j++)
        {
            x1 = i - k + 1, y1 = j - k + 1;
            s = f[i][j] - f[x1 - 1][j] - f[i][y1 - 1] + f[x1 - 1][y1 - 1];
            // cout << "!! " << x << ' ' << i << ' ' << j << ' ' << x1 << ' ' << y1 << '\n';
            // cout << s << ' ' << ((k * k / 2) + 1) << '\n';
            // cout << '\n';
            if (s >= zw)
            {

                return 1;
            }
            // else
            // {
            //     return 0;
            // }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    if (k * k % 2 == 1)
    {
        zw = (k * k / 2) + 1;
    }
    else
    {
        zw = (k * k) / 2;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    ll l = 1, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
