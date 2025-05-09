#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1010;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll p[1010][21];
vector<vector<ll>> ve(MAXN + 10);
vector<ll> vis(MAXN + 10);
vector<ll> d(MAXN + 10);
vector<ll> dep(MAXN + 10);
void dfs(ll u, ll f)
{
    d[u] = d[f] + 1;
    p[u][0] = f;
    for (int i = 1; i <= 20; i++)
    {
        p[u][i] = p[p[u][i - 1]][i - 1];
    }
    for (auto it : ve[u])
    {
        if (it == f)
        {
            continue;
        }
        dfs(it, u);
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
    cin >> n;

    map<ll, ll> ma;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    ll dd = 0, wd = 0;
    function<void(ll x, ll dx)> dfs1 = [&](ll x, ll dx)
    {
        ma[dx]++;
        dd = max(dd, dx);
        dep[x] = dx;
        for (auto it : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            dfs1(it, dx + 1);
        }
    };
    vis[1] = 1;
    dfs1(1, 1);
    for (auto it : ma)
    {
        wd = max(wd, it.second);
    }
    ll x, y;
    cin >> x >> y;
    dfs(1, 0);
    ll p = lca(x, y);
    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }
    vis[p] = 1;
    dfs1(p, 0);
    cout << dd << '\n';
    cout << wd << '\n';
    cout << 2 * dep[x] + dep[y] << '\n';
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