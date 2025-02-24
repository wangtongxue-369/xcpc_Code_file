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
ll lcm(ll s1, ll s2)
{
    return (s2 / __gcd(s1, s2) * s1);
}
void solve()
{
    cin >> n;
    ans = 0;
    ll k = 1;
    ll res = n; // 1e16
    for (ll i = 2; i <= 10000; i++)
    {
        k = lcm(k, i);
        ll s1 = (n / k);
        ans = (ans + (res - s1) * i) % mod;
        res = s1;
        // if (res == 0)
        // {
        //     break;
        // }
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
