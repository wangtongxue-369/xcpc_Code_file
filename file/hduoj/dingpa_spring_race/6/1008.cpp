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
ll C(ll i, ll x)
{
    return ((i) * (i - 1) / 2) % mod;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll p = a[1];
    ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans = (ans + p * a[i]) % mod;
        p = (p + a[i]) % mod;
    }
    ll c = 1;
    ////cout << ans << '\n';
    for (ll i = n; i >= 2; i--)
    {
        // (C i,2)
        c = (c * C(i, 2) % mod) % mod;
    }
    cout << ans << ' ' << c << '\n';
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