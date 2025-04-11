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
ll fa[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void nuio(ll x, ll y)
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
    for (int i = 1; i < MAXN; i++)
    {
        fa[i] = i;
    }
    ll k;
    cin >> n >> m >> k;
    ll u, v, w;
    set<PII> se;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        if (w == -1)
        {
            se.insert({u, v});
            se.insert({v, u});
        }
        else
        {
            nuio(u, v);
        }
    }
    while (k--)
    {
        cin >> u >> v;
        if (se.contains({u, v}))
        {
            if (find(u) == find(v))
            {
                cout << "OK but...\n";
            }
            else
            {
                cout << "No way\n";
            }
        }
        else if (find(u) == find(v))
        {
            cout << "No problem\n";
        }
        else
        {
            cout << "OK\n";
        }
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