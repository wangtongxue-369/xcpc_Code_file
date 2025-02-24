#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m = 0, ans = 0, a[MAXN], d[MAXN], dpt[MAXN];
vector<vector<ll>> ve(MAXN + 100);
ll sz[MAXN];
void dfs(ll i, ll fa)
{
    sz[i] = 0;
    d[i] = d[fa] + 1;
    m = max(m, d[i]);
    dpt[i] = d[i];

    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        dfs(it, i);
        if (dpt[i] != d[i])
        {
            if (dpt[i] < dpt[it])
            {
                a[dpt[i] + 1] += sz[i];
                a[dpt[it] + 1] -= sz[i];
                dpt[i] = dpt[it];
            }
            else
            {
                a[dpt[it] + 1] += sz[it];
                a[dpt[i] + 1] -= sz[it];
            }
        }
        else
        {
            dpt[i] = dpt[it];
        }
        sz[i] += sz[it];
    }
    a[d[i]] += sz[i];
    a[d[i] + 1] -= sz[i];
    sz[i]++;
}
void solve()
{
    m = 0;
    cin >> n;
    ll u, v;
    for (int i = 1; i <= n; i++)
    {
        ve[i].clear();
        a[i] = 0;
        sz[i] = 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dfs(1, -1);
    ll tmp = 0;
    ans = 1e18;
    for (int i = 1; i <= m; i++)
    {
        tmp += a[i];
        ans = min(ans, tmp);
    }
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
