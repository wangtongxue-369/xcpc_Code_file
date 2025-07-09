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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN], d1[MAXN], fa[MAXN], dis[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        ll xd = fa[x];
        fa[x] = find(fa[x]);
        dis[x] += dis[xd];
    }
    return fa[x];
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        dis[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> d1[i];
    }
    ll x, y, d;
    for (int i = 1; i <= m; i++)
    {
        x = a[i], y = b[i], d = d1[i];
        ll tx = find(x);
        ll ty = find(y);
        if (tx != ty || dis[x] - dis[y] == d)
        {
            fa[tx] = ty;
            dis[tx] = d + dis[y] - dis[x];
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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