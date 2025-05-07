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

    ll u, v;
    cin >> n >> m;
    vector<vector<ll>> ve(n + 10);
    vector<ll> vis(n + 10);
    for (ll i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    ll p = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (ve[i].size() == 1)
        {
            p = i;
            vis[i] = 1;
        }
    }
    p = ve[p][0];
    ll t = 0;
    for (auto it : ve[p])
    {
        if (vis[it] == 0)
        {
            t = it;
        }
    }
    cout << ve[t].size() << ' ' << ve[p].size() - 1 << '\n';
}
// 先for一遍 找出来
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