#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define lld 0x3f
const ll mod = 1e9 + 7;
ll _ = 1, n, m, ans = 0, s, d[5000005];
ll p[500005][21];
vector<ll> e[500005];
void dfs(ll u, ll f)
{
    d[u] = d[f] + 1;
    p[u][0] = f;
    for (int i = 1; i <= 20; i++)
    {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        ll v = e[u][i];
        if (v == f)
        {
            continue;
        }
        dfs(v, u);
    }
}
ll lca(ll u, ll v)
{
    if (d[u] < d[v])
    {
        swap(u, v);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (d[p[u][i]] >= d[v])
        {
            u = p[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (p[u][i] != p[v][i])
        {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return p[u][0];
}
void solve()
{
    ll u, v;
    cin >> n >> m;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}