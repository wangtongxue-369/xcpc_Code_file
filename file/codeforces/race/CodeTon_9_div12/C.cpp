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
void solve()
{
    ll x;
    cin >> x >> m;
    ll c = 0;
    ll s = x;
    while (s)
    {
        s /= 2;
        c++;
    }
    if ((1 << (c - 1)) > m)
    {
        cout << 0 << '\n';
        return;
    }
    ans = 0;
    for (ll i = 1; i <= min(m, (ll)(1 << c)); i++)
    {
        ll d = (x ^ i);
        if (d == 0)
        {
            continue;
        }
        if (x % d == 0)
        {
            ans++;
            continue;
        }
        if (i % d == 0)
        {
            ans++;
            continue;
        }
    }
    cout << ans << '\n';
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
