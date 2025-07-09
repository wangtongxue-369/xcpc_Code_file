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
    for (int i = 1; i <= 2 * n; i++)
    {
        fa[i] = i;
    }
    char c;
    ll p, q;
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> p >> q;
        if (c == 'F')
        {
            unio(p, q);
        }
        else
        {
            unio(p + n, q);
            unio(q + n, p);
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == i)
        {
            ans++;
        }
    }
    cout << ans << '\n';
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