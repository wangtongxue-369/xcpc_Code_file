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
#define vi vector<ll>
#define A(x) array<ll, x>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
class LCA
{
    int n, s;
    vi dep, dis;
    vector<vi> fa;
    vector<vector<A(2)>> e;
    void dfs(int u, int f)
    {
        fa[u][0] = f, dep[u] = dep[f] + 1;
        for (int i = 1; i < 32; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (auto [v, w] : e[u])
            if (v != f)
            {
                dis[v] = dis[u] + w;
                dfs(v, u);
            }
    }

public:
    LCA(int n_, int s_, vector<vector<A(2)>> &e_) : n(n_), s(s_), e(e_)
    {
        dep.resize(n + 1), dis.resize(n + 1, 0);
        fa.resize(n + 1, vi(32, 0));
        dfs(s, 0);
    }
    int lca(int u, int v)
    {
        if (dep[u] > dep[v])
            swap(u, v);
        int diff{dep[v] - dep[u]};
        for (int i = 0; diff; ++i, diff >>= 1)
        {
            if (diff & 1)
                v = fa[v][i];
        }
        if (u == v)
            return u;
        for (int i = 31; i >= 0; i--)
        {
            if (u == v)
                break;
            if (fa[u][i] != fa[v][i])
                u = fa[u][i], v = fa[v][i];
        }
        return fa[u][0];
    }
    // 任意两点距离
    int dist(int u, int v)
    {
        int p{lca(u, v)};
        return dis[u] + dis[v] - 2 * dis[p];
    }
    // u 向上第 k 个祖先
    int kth_fa(int u, int k)
    {
        for (int i = 0; i < 32; i++)
            if (k >> i & 1)
                u = fa[u][i];
        return u;
    }
    // u -> v 路径上第 k 个点
    int kth_path(int u, int v, int k)
    {
        int p{lca(u, v)}, d1{dep[u] - dep[p]};
        if (k <= d1)
            return kth_fa(u, k);
        else
        {
            int d2{dep[v] - dep[p]}, k2{d1 + d2 - k};
            return kth_fa(v, k2);
        }
    }
};
void solve()
{
    ll u, v, w;
    cin >> n >> m;
    vector<vector<A(2)>> ve(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
    LCA lca = LCA(n, 1, ve);
    while (m--)
    {
        cin >> u >> v;
        cout << lca.dist(u, v) << '\n';
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