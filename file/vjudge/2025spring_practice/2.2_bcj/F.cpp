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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], fa[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(ll s1, ll s2)
{
    ll t1 = find(s1), t2 = find(s2);
    if (t1 != t2)
    {
        fa[t1] = t2;
    }
}
void solve()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    ll u, v;
    ll ew = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if (find(u) == find(v))
        {
            ew++;
        }
        // else
        {
            unio(u, v);
        }
        map<ll, ll> ma;
        for (int i = 1; i <= n; i++)
        {
            ma[find(i)]++;
        }
        ans = 0;
        vector<ll> ve;
        for (auto it : ma)
        {
            ve.push_back(it.second);
        }
        ll p = ew + 1;
        ans = 0;
        sort(ve.begin(), ve.end(), greater<ll>());
        for (int i = 0; i < ve.size() && p; i++)
        {
            ans += ve[i];
            p--;
        }
        cout << ans - 1 << '\n';
    }
}
// 做i次介绍，并且满足i及之前的给的连接，问你i次介绍最多可以有多少人认识。
// 如果新连接的是已经连接过的，那么这个新连接的机会可以用来连接其他的
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