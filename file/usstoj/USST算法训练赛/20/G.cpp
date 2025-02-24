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
ll _ = 1, n, m, ans = 0, a[MAXN], fa[MAXN];
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
        ans--;
    }
}
void solve()
{
    cin >> n >> m;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        ll x, y;
        cin >> x >> y;
        unio(x, y);
    }
    cout << (1ll << (n - ans));
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
