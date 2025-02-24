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
    ll count = 0;
    for (ll k = 1; k * x <= (x | m); ++k)
    {
        ll z = k * x;
        ll y = z ^ x;
        if (y >= 1 && y <= m)
        {
            count++;
        }
    }

    for (ll y = 1; y <= m; ++y)
    {
        ll z = x ^ y;
        if (z % y == 0)
        {
            count++;
        }
        }

    cout << count << '\n';
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
