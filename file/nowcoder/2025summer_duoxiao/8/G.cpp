#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsicnmed long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct DSU
{
    vector<int> fa, sz, used;
    DSU(int n)
    {
        fa.assign(n, 0);
        sz.assign(n, 1);
        used.assign(n, 0);
        for (int i = 0; i < n; i++)
            fa[i] = i;
    }
    int find(int u)
    {
        if (fa[u] == u)
            return u;
        fa[u] = find(fa[u]);
        return fa[u];
    }
    void unite(int u, int v)
    {
        fa[v] = u;
        sz[u] += sz[v];
    }
    bool same(int u, int v)
    {
        return find(u) == find(v);
    }
    int size(int u)
    {
        u = find(u);
        return sz[u];
    }
};
void solve()
{
    ll k, u, v, w;
    cin >> n >> m >> k;
    vector<array<ll, 3>> t;
    vector<vector<PII>> ve(n + 10);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, i});
        ve[v].push_back({u, i});
        t.push_back({u, v, w});
    }
    vector<bool> vis(n + 10);
    ll sum = 0;
    function<void(ll x)> dfs = [&](ll x)
    {
        sum++;
        for (auto [it, l] : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            dfs(it);
        }
    };
    ll c = 0;
    vector<ll> cc;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            c++;
            sum = 0;
            vis[i] = 1;
            dfs(i);
            cc.push_back(sum);
        }
        if (c >= 3)
        {
            cout << 0 << '\n';
            return;
        }
    }
    if (c == 2)
    {
        cout << ((cc[0] * cc[1]) % mod * k) % mod << '\n';
        return;
    }
    sort(t.begin(), t.end(), [](const array<ll, 3> &s1, const array<ll, 3> &s2)
         { return s1[2] < s2[2]; });

    // n*(n-1)/2 在我当前选了的集合里面任意选一个连接未选集合
    DSU dsu(n + 5);
    ll kx = n * (n - 1);
    ll ans = 0;
    ll tot = m;
    ll now = 1;
    vis.clear();
    vis.resize(m + 10, 0);
    for (int i = 0; i < m; i++)
    {
        w = t[i][2], u = t[i][0], v = t[i][1];
        ll U = dsu.find(u), V = dsu.find(v);
        if (U == V)
        {
            continue;
        }
        ll p = kx / 2;
        ll val = ((p - tot) % mod + mod) % mod;
        ll de = ((w - now) % mod + mod) % mod;
        ans = (ans + ((__int128_t)de * val) % mod) % mod;
        now = w;
        kx -= (1ll * dsu.size(U) * (n - dsu.size(U)));
        kx -= (1ll * dsu.size(V) * (n - dsu.size(V)));
        if (ve[U].size() < ve[V].size())
        {
            swap(U, V);
        }
        dsu.unite(U, V);
        ll tm = dsu.find(U);
        kx += (1ll * dsu.size(tm) * (n - dsu.size(tm)));
        for (auto [x, i] : ve[V])
        {
            ll cnm = dsu.find(x);
            if (cnm == tm)
            {
                if (vis[i] == 0)
                {
                    tot--;
                    vis[i] = 1;
                }
            }
            else
            {
                ve[tm].emplace_back(cnm, i);
            }
        }
        ve[V].clear();
    }
    cout << ans << '\n';
}
// 分块
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