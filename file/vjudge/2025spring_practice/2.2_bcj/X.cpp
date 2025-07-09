#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, c[MAXN], fa[MAXN];
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
PII a[MAXN];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].second;
        cin >> a[i].first;
    }
    ans = 0;
    sort(a + 1, a + 1 + m);
    ll x = n;
    ll pr = n;
    for (int i = 1; i <= m; i++)
    {
        x = __gcd(x, a[i].second);
        // ll p = x;
        ans += a[i].first * (pr - x);
        pr = x;
    }
    if (x > 1)
    {
        cout << -1 << '\n';
        return;
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