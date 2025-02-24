#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], d[MAXN], k[MAXN];
ll fa[MAXN];
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
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> d[i] >> k[i];
    }
    for (int x = 1; x <= 10; x++)
    {
        vector<ll> f(n + 10, 0);
        for (int i = 1; i <= m; i++)
        {
            if (d[i] == x)
            {
                f[a[i]]++;
                f[a[i] + d[i] * k[i]]--;
            }
        }
        for (int i = x; i <= n; i++)
        {
            f[i] += f[i - x];
        }
        for (int i = 1; i <= n; i++)
        {
            if (f[i] != 0)
            {
                unio(i, i + x);
            }
        }
    }
    set<ll> se;
    for (int i = 1; i <= n; i++)
    {
        ll x = find(i);
        se.insert(fa[i]);
    }
    cout << se.size() << '\n';
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
