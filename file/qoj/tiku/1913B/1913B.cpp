/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
bool cmp(ll s1, ll s2)
{
    return f[s1] > f[s2];
}
void solve()
{
    cin >> n >> m;
    ll u, v;
    vector<vector<ll>> ve(n + 10);
    vector<ll> vis(n + 10, 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        sort(ve[i].begin(), ve[i].end(), cmp);
    }
    function<bool(ll x)> check = [&](ll x)
    {
        for (auto it : ve[x])
        {
            if (!vis[it])
            {
                return 1;
            }
        }
        return 0;
    };
    vector<PII> an;
    function<ll(ll x, ll i)> dfs = [&](ll x, ll i)
    {
        if (i > n)
        {
            return i;
        }
        ll p = i;
        while (p <= n && ve[x].size())
        {
            while (ve[x].size() && vis[ve[x].back()])
            {
                ve[x].pop_back();
            }
            if (ve[x].size() == 0)
            {
                break;
            }
            if (ve[x].back() == a[p])
            {
                vis[a[p]] = 1;
                p = dfs(a[p], p + 1);
            }
            else
            {
                an.push_back({x, a[p]});
                vis[a[p]] = 1;
                p = dfs(a[p], p + 1);
            }
        }
        return p;
    };
    for (int i = 1; i <= n; i++)
    {
        if (vis[a[i]] == 0)
        {
            vis[a[i]] = 1;
            ll p = dfs(a[i], i + 1);
        }
    }
    cout << an.size() << '\n';
    for (auto it : an)
    {
        cout << it.first << ' ' << it.second << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}