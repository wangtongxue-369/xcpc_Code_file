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
    ll k, y, u, v, w;
    cin >> n >> m >> k >> y;
    vector<vector<PII>> ve(n + 10);
    vector<ll> vis(n + 10);
    vector<ll> dep(n + 10);
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        ve[v].push_back({u, w});
    }
    bool fh = 0;
    ll maxn = 0;
    function<void(ll x, ll v)> dfs = [&](ll x, ll v)
    {
        maxn = max(maxn, v);
        for (auto it : ve[x])
        {
            if (vis[it.first])
            {
                fh = 1;
                return;
            }
            vis[it.first] = 1;
            dfs(it.first, it.second + v);
            if (fh)
            {
                return;
            }
        }
    };
    vis[y] = 1;
    dfs(y, 0);
    if (fh)
    {
        cout << "YES\n";
        return;
    }
    if (maxn >= k)
    {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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