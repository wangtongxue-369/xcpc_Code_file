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
    map<ll, vector<ll>> ma;
    vector<ll> vis(n + 10);
    vector<ll> cntd(n + 10); // i深度的节点有几个
    vector<ll> mxd(n + 10);  // 子树节点最大深度为i的节点的数量
    vector<ll> dep(n + 10);
    for (ll i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    // 维护每个点的深度，维护子树最大深度的点的数量
    ll minn = 1e18;
    function<ll(ll x, ll d)> dfs = [&](ll x, ll d)
    {
        dep[x] = d;
        ll md = dep[x];
        ll res = d;
        for (auto it : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            ll t = dfs(it, d + 1);
            res = max(t, res);
            // md = max(md, dep[it]);
        }
        cntd[d]++;
        mxd[res]++;
        return res;
    };
    vis[1] = 1;
    mxd[dfs(1, 1)]++;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << cntd[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << mxd[i] << ' ';
    // }
    // cout << '\n';

    ans = 1e18;
    ll sum = cntd[1];
    for (ll i = 2; i <= n; i++)
    {
        sum += cntd[i];
        ans = min(ans, n - sum);
        sum -= mxd[i];
    }
    cout << ans << '\n';
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