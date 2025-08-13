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
    ll x, y;
    cin >> x >> y;
    ll s = x + y;
    if (s % 2 == 1)
    {
        cout << -1 << '\n';
        return;
    }
    if (y < x)
    {
        swap(x, y);
    }
    ll d = __gcd(x, y);
    ll tot = s / d;
    if ((tot & (tot - 1)) == 0 && (x / d) % 2 == 1)
    {
        ll p = 0;
        ll t = tot;
        while (t > 1)
        {
            p++;
            t /= 2;
        }
        cout << p << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
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