/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
    ll l, r;
    cin >> l >> r;
    n = r;
    // ll p = 2e5, cnt = 0;
    // while (p)
    // {
    //     p >>= 1;
    //     cnt++;
    // }
    // cout << cnt << '\n';   18   20
    vector<ll> vis(n + 10);
    for (int i = 0; i <= n; i++)
    {
        a[i] = -1;
    }
    // x 配 1111111111-x
    // 和越大的肯定越优
    ll p = 1;
    while ((1ll << (p + 1)) <= n)
    {
        p++;
    }
    for (int i = p + 1; i >= 0; i--)
    {
        ll k = (1ll << i) - 1;
        for (int j = 0; j <= n; j++)
        {
            if (j > k)
            {
                break;
            }
            if (k - j < 0 || k - j > n || vis[k - j] || vis[j])
            {
                continue;
            }
            vis[k - j] = 1;
            vis[j] = 1;
            a[k - j] = j, a[j] = k - j;
        }
    }
    ll cnt = 0;
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == -1)
        {
            cnt++;
        }
    }
    // cout << cnt << '\n';
    ans = 0;
    for (ll i = 0; i <= n; i++)
    {
        if (a[i] == -1)
        {
            a[i] = i;
        }
        ans += (i | a[i]);
    }
    cout << ans << '\n';
    for (int i = 0; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
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