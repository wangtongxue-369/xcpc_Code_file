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
vector<vector<PII>> ve;
struct SCC
{
    ll n;
    vector<vector<ll>> &adj;
    vector<set<ll>> scc;
    vector<ll> stk;
    vector<ll> dfn, low, bel, ishf;
    ll cur = 0, cnt = 0;
    SCC(int n_, vector<vector<ll>> &adj_) : adj(adj_), n(n_)
    {
        init(n);
    }
    void init(ll n)
    {
        this->n = n;
        dfn.assign(n + 1, 0);
        low.resize(n + 1);
        bel.assign(n + 1, -1);
        ishf.assign(n + 1, 0);
        stk.clear();
        cur = 0;
        work();
        work2();
    }
    void dfs(ll x)
    {
        dfn[x] = low[x] = ++cur;
        stk.push_back(x);
        for (auto y : adj[x])
        {
            if (dfn[y] == 0)
            {
                dfs(y);
                low[x] = min(low[x], low[y]);
            }
            else if (bel[y] == -1)
            {
                low[x] = min(low[x], dfn[y]);
            }
        }

        if (dfn[x] == low[x])
        {
            int cnt = scc.size();
            scc.push_back({});
            int y;
            do
            {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
                scc.back().insert(y);
            } while (y != x);
        }
    }
    vector<vector<ll>> rebuild()
    {
        ll cnt = scc.size();
        vector<vector<ll>> g(cnt);
        for (int x = 0; x < n; x++)
        {
            for (auto y : adj[x])
            {
                if (bel[x] != bel[y])
                {
                    g[bel[y]].push_back(bel[x]);
                }
            }
        }
        return g;
    }
    void work()
    {
        for (int i = 0; i < n; i++)
        {
            if (dfn[i] == 0)
            {
                dfs(i);
            }
        }
    }
    void work2()
    {
        vector<ll> fz(n + 10, 1e18);
        for (int i = 0; i < scc.size(); i++)
        {
            ll x = *scc[i].begin();
            fz[x] = 0;
            queue<ll> q;
            q.push(x);
            bool flag = 0;
            while (!q.empty())
            {
                auto u = q.front();
                q.pop();
                for (auto [v, w] : ve[u])
                {
                    if (scc[i].contains(v))
                    {
                        if (fz[v] == 1e18)
                        {
                            fz[v] = fz[u] + w;
                            q.push(v);
                        }
                        else if (fz[v] != fz[u] + w)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
            }
            ishf[i] = flag;
        }
    }
};
ll mm(ll a, ll b)
{
    return ((a % n + n) % n + (b % n + n) % n) % n;
}
ll mm(ll a)
{
    return (a % n + n) % n;
}
void solve()
{
    ll xw;
    cin >> n >> m >> xw;
    ve.resize(n + 10);
    vector<vector<ll>> adj(n + 10);
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[mm(u)].push_back({mm(u, v), v});
        adj[mm(u)].push_back(mm(u, v) % n);
    }
    SCC scc(n, adj);
    auto tu = scc.rebuild();
    vector<bool> vis(tu.size() + 10);
    queue<ll> q;
    for (ll i = 0; i < scc.scc.size(); i++)
    {
        if (scc.ishf[i])
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (auto u : tu[it])
        {
            if (vis[u])
            {
                continue;
            }
            scc.ishf[u] = 1;
            vis[u] = 1;
            q.push(u);
        }
    }
    while (xw--)
    {
        ll x;
        cin >> x;
        x = mm(x);
        ll be = scc.bel[x];

        if (scc.ishf[be])
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
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