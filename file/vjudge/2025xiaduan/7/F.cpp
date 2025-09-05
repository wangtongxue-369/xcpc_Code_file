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
#define int long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];

// SCC
struct SCC
{
    int n;
    vector<vector<int>> &adj; // 临接表
    vector<vector<int>> scc;  // 强连通分量集合
    vector<int> stk;          // 递归栈
    vector<int> dfn, low, bel;
    int cur, cnt;
    // bel 强连通分量的编号

    SCC(int n_, vector<vector<int>> &adj_) : adj(adj_), n(n_) { init(n); }

    void init(int n)
    {
        this->n = n;
        dfn.assign(n + 1, 0);
        low.resize(n + 1);
        bel.assign(n + 1, -1);
        stk.clear();
        cur = 0;
        work();
    }

    void dfs(int x)
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
                scc.back().push_back(y);
            } while (y != x);
        }
    }
    vector<vector<int>> rebuild()
    {
        int cnt = scc.size();
        vector<vector<int>> g(cnt);
        for (int x = 1; x <= n; x++)
        {
            for (auto y : adj[x])
            {
                if (bel[x] != bel[y])
                {
                    g[bel[x]].push_back(bel[y]);
                }
            }
        }
        return g;
    }
    void work()
    {
        for (int i = 1; i <= n; i++)
        {
            if (dfn[i] == 0)
            {
                dfs(i);
            }
        }
    }
};
void solve()
{
    ll k, q;
    cin >> n >> k >> q;
    vector<vector<ll>> ve(n + 10);
    vector<vector<int>> a(k + 10, vector<int>(n + 10));
    set<PII> se;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
        for (int j = 1; j < n; j++)
        {
            if (!se.contains({a[i][j], a[i][j + 1]}))
            {
                ve[a[i][j]].push_back(a[i][j + 1]);
                se.insert({a[i][j], a[i][j + 1]});
            }
        }
    }
    SCC Scc(n, ve);

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = Scc.bel[a[i][j]];
        }
    }
    vector<vector<PII>> p(k + 10, vector<PII>(n + 10));
    vector<vector<ll>> f(k + 10, vector<ll>(n + 10));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ll x = j;
            while (x + 1 <= n && a[i][x + 1] == a[i][j])
            {
                x++;
            }
            for (int w = j; w <= x; w++)
            {
                p[i][w] = {j, x};
            }
            j = x;
        }
        for (int j = 1; j <= n; j++)
        {
            auto [l, r] = p[i][j];
            for (int w = l; w <= r; w++)
            {
                f[i][w] = f[i][w - 1] + w - l;
            }
            j = r;
        }
    }
    ll pv = 0;
    ll dx, l, r;
    while (q--)
    {
        ans = 0;
        cin >> dx >> l >> r;
        dx = (dx + pv) % k + 1;
        l = (l + pv) % n + 1;
        r = (r + pv) % n + 1;
        ll pl = p[dx][l].first, pr = p[dx][l].second, el = p[dx][r].first, er = p[dx][r].second;
        ll fend = min(pr, r);
        ans += (fend - l) * (fend - l + 1) / 2;
        l = fend;
        ans += f[dx][r] - f[dx][l];
        cout << ans << '\n';
        pv = ans;
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