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
    cin >> n;
    ll u, v;
    vector<vector<ll>> ve(n + 10);
    vector<ll> vis(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    ans = 0;
    ll md = 0;
    function<void(ll x, ll d)> dfs = [&](ll x, ll d)
    {
        md = max(md, d);
        for (auto it : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            dfs(it, d + 1);
        }
    };
    for (auto it : ve[1])
    {
        vis[1] = 1;
        vis[it] = 1;
        dfs(it, 1);
        ans += md;
        md = 0;
    }
    cout << ans << '\n';
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