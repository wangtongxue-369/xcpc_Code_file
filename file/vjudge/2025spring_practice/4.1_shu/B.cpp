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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN + 10);
ll vis[MAXN + 10];
ll dis[MAXN + 10];
void dfs(ll x, ll d)
{
    if (dis[x])
    {
        return;
    }
    dis[x] = d;
    for (auto it : ve[x])
    {
        dfs(it, d);
    }
}
void solve()
{
    cin >> n >> m;
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[v].push_back(u);
    }
    ll p = 1;
    vector<ll> po;
    for (ll i = n; i >= 1; i--)
    {
        dfs(i, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << ' ';
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