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
    vector<vector<ll>> ve(n + 10);
    vector<PII> an(n + 10);
    vector<ll> vis(n + 10);
    vector<ll> ds(n + 10);
    vector<ll> dep(n + 10);
    vector<vector<ll>> vu(n + 10);
    //  维护每个节点及其子树的节点数
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    function<ll(ll x, ll d)> dfs = [&](ll x, ll d)
    {
        ll res = 1;
        dep[x] = d;
        vu[d].push_back(x);
        for (auto it : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            ds[it] = dfs(it, d + 1);
            res += ds[it];
        }
        return res;
    };
    vis[1] = 1;
    ds[1] = dfs(1, 1);
    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << ds[i] << ' ';
    // }
    // cout << '\n';

    ll su = 0;
    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (auto it : vu[i])
        {
            sum += ds[it];
        }
        for (auto it : vu[i])
        {
            an[it].first = dep[it];
            an[it].second = sum + su - ds[it] + 1;
        }
        su += vu[i].size();
    }
    for (int i = 1; i <= n; i++)
    {
        cout << an[i].first << ' ' << an[i].second << '\n';
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