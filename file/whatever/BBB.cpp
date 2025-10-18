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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll u, v, w;
    vector<PII> vv;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        vv.push_back({u, v});
    }
    vector<ll> dfn(n + 10), low(n + 10), stk(n + 10), instk(n + 10), belong(n + 10);
    ll cnt = 0, top = 0;
    vector<ll> in(n + 10), dp(n + 10);
    function<void(ll u)> tarjan = [&](ll u)
    {
        dfn[u] = low[u] = ++cnt;
        stk[++top] = u;
        instk[u] = 1;
        for (auto it : ve[u])
        {
            if (!dfn[it])
            {
                tarjan(it);
                low[u] = min(low[u], low[it]);
            }
            else if (instk[it])
            {
                low[u] = min(low[u], dfn[it]);
            }
        }
        if (dfn[u] == low[u])
        {
            do
            {
                instk[stk[top]] = 0;
                belong[stk[top]] = u;
                if (stk[top] != u)
                {
                    a[u] += a[stk[top]];
                }
            } while (stk[top--] != u);
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    vector<vector<ll>> g(n + 10);
    for (auto [u, v] : vv)
    {
        ll x = belong[u], y = belong[v];
        if (x != y)
        {
            g[x].push_back(y);
            in[y]++;
        }
    }
    function<void()> po = [&]()
    {
        queue<ll> q;
        for (int i = 1; i <= n; i++)
        {
            if (i == belong[i] && !in[i])
            {
                q.push(i);
                dp[i] = a[i];
            }
        }
        while (!q.empty())
        {
            ll s = q.front();
            q.pop();
            for (auto it : g[s])
            {
                dp[it] = max(dp[it], dp[s] + a[it]);
                if (--in[it] == 0)
                {
                    q.push(it);
                }
            }
        }
    };
    po();
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
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