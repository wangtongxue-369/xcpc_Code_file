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
    // 每个点子树的节点数
    // 每个点的深度
    cin >> n;
    ll u, v;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<ll> dep(n + 10);
    vector<ll> su(n + 10);
    function<ll(ll x, ll fa, ll t)> dfs = [&](ll x, ll fa, ll t)
    {
        dep[x] = t;
        ll sum = 0;
        if (ve[x].size() == 1 && x != 1)
        {
            return (ll)1;
        }
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            sum += dfs(it, x, t + 1);
        }
        su[x] = sum;
        return sum + 1;
    };
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)
    {
        cout << dep[i] << ' ' << n - su[i] << '\n';
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