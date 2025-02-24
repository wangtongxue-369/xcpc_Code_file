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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], du[MAXN];
vector<vector<ll>> ve(MAXN + 10);
ll maxn = 0;
void dfs(ll i)
{
    if (i >= n + 1)
    {
        return;
    }
    for (auto it : ve[i])
    {
        while (it >= maxn)
        {
            if (it > maxn)
            {
                ans++;
            }
            ll cur = maxn;
            maxn++;
            dfs(cur);
        }
    }
}
void solve()
{
    maxn = 2;
    ans = 0;
    cin >> n >> m;
    ll u, v;
    ans = 0;
    for (int i = 0; i <= n; i++)
    {
        ve[i].clear();
        du[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
        du[u]++, du[v]++;
    }
    ve[1].push_back(n + 1);
    for (int i = 1; i <= n; i++)
    {
        sort(ve[i].begin(), ve[i].end());
    }
    dfs(1);
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
