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
ll _ = 1, n, m, ans = 0, a[MAXN], fa[MAXN], c[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(ll x, ll y)
{
    ll tx = find(x);
    ll ty = find(y);
    if (tx != ty)
    {
        fa[tx] = ty;
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        unio(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        ll d = find(i);
    }
    map<ll, vector<ll>> ma;
    for (int i = 1; i <= n; i++)
    {
        ma[find(i)].push_back(i);
    }
    ans = 0;
    for (auto [i, ve] : ma)
    {
        map<ll, ll> k;
        ll maxn = 0;
        for (auto it : ve)
        {
            k[c[it]]++;
            maxn = max(maxn, k[c[it]]);
        }
        ans += (ve.size() - maxn);
    }
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
