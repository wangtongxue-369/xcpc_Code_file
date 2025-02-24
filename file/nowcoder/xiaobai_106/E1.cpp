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
ll _ = 1, n, m; // a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN + 10);
vector<ll> dep(MAXN + 10, 0);
ll ans = 0;
ll dfs(ll i, ll det, ll fa)
{
    ll res = det;
    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        res = max(res, det + dfs(it, 1, i));
    }
    dep[i] = res;
    return res;
}
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void dfs2(ll i, ll det, ll fa)
{
    vector<ll> v;
    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        v.push_back(dep[it]);
    }
    if (v.size() >= 2)
    {
        sort(v.begin(), v.end(), cmp);
        ans = max(ans, det + v[0] + v[1] - 1);
    }
    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        dfs2(it, det + 1, i);
    }
}
void solve()
{
    cin >> n;
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    dep[1] = dfs(1, 1, -1);
     ans =dep[1];
    dfs2(1, 1, -1);
   
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
