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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    if (m < n || m > n * (n + 1) / 2)
    {
        cout << -1 << '\n';
        return;
    }
    if (m > n + (n - 1) * n / 2)
    {
        cout << -1 << '\n';
        return;
    }
    // 比他小的那部分就是自己 比他大的是它
    // n*k-k*(k-1)/2;
    // ll k;
    // for (ll i = 1; i <= n; i++)
    // {
    //     if (n * i - i * (i - 1) / 2 >= m)
    //     {
    //         k = i;
    //         break;
    //     }
    // }
    ll c = m - n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    ll p = 1;
    vector<ll> vis(n + 10, 0);
    ll lat = 0;
    if (c != 0)
    {
        for (int i = n; i >= 1; i--)
        {
            if (c >= i - 1)
            {
                vis[i] = 1;
                if (lat == 0)
                {
                    lat = i;
                }
                c -= i - 1;
            }
        }
    }
    if (n == m)
    {
        cout << 1 << '\n';
        for (int i = 2; i <= n; i++)
        {
            cout << i - 1 << ' ' << i << '\n';
        }
        return;
    }
    cout << lat << '\n';
    for (int i = n; i >= 1; i--)
    {
        if (i == lat)
        {
            continue;
        }
        if (vis[i])
        {
            cout << lat << ' ' << i << '\n';
            lat = i;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (vis[i] == 0)
        {
            cout << lat << ' ' << i << '\n';
            lat = i;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}