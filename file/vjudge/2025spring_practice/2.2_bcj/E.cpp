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
ll _ = 1, n, m, ans = 0, a[MAXN], k[MAXN], fa[MAXN];
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
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    ll p1, p;
    for (int i = 1; i <= m; i++)
    {
        cin >> k[i];
        if (k[i])
        {
            cin >> p1;
        }
        for (int j = 2; j <= k[i]; j++)
        {
            cin >> p;
            unio(p1, p);
        }
    }
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        ma[find(i)]++;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ma[find(i)] << ' ';
    }
    cout << '\n';
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