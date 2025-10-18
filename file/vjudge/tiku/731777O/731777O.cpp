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
    ll u, v;
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<ll> siz(n + 10), weight(n + 10), ce;
    function<void(ll x, ll fa)> dfs = [&](ll x, ll fa)
    {
        siz[x] = 1;
        weight[x] = 0;
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            dfs(it, x);
            siz[x] += siz[it];
            weight[x] = max(weight[x], siz[it]);
        }
        weight[x] = max(weight[x], n - siz[x]);
        if (weight[x] <= n / 2)
        {
            ce.push_back(x);
        }
    };
    dfs(1, 0);
    if (ce.size() == 1)
    {
        cout << ve[ce[0]][0] << ' ' << ce[0] << '\n';
        cout << ve[ce[0]][0] << ' ' << ce[0] << '\n';
    }
    else
    {
        for (auto it : ve[ce[0]])
        {
            if (it != ce[1])
            {
                cout << ce[0] << ' ' << it << '\n';
                cout << ce[1] << ' ' << it << '\n';
                return;
            }
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