#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 300005;
ll _ = 1, n, m, ans = 0, a[MAXN]; // vis[10 * MAXN + 100];
map<ll, vector<ll>> ma;
map<ll, bool> vis;
void dfs(ll u, ll fa)
{
    ans = max(ans, u);
    vis[u] = 1;
    for (auto it : ma[u])
    {
        if (it == fa)
        {
            continue;
        }
        if (vis[it] == 1)
        {
            continue;
        }
        dfs(it, u);
    }
}
void solve()
{
    // memset(vis, 0, sizeof(vis));
    vis.clear();
    cin >> n;
    ma.clear();
    for (ll i = 1; i <= n; i++)
    {
        vis[i] = 0;
        cin >> a[i];
        ma[a[i] - 1 + i].push_back(a[i] + 2 * (i - 1));
    }
    ans = 0;
    dfs(n, 0);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
