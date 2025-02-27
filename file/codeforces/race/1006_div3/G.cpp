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
ll z(ll x)
{
    return x * (x + 1) * (2 * x + 1) / 6;
}
void solve()
{
    ans = 0;
    ll x, p, k, cnt;
    cin >> n >> k;
    function<ll(ll n, ll p)> rev = [](ll n, ll p)
    {
        ll res = 0;
        while (n)
        {
            res = res * p + n % p;
            n /= p;
        }
        res %= mod;
        return res;
    };
    for (ll l = 2, r; l <= min(n, k); l = r + 1)
    {
        if (l * l <= n)
        {
            ans += rev(n, l);
            r = l;
        }
        else
        {
            ll s1 = n / l;
            r = min(k, (n / (n / l)));
            ll a1 = n % l, an = n % r;
            ans = (ans + s1 * (r - l + 1) % mod) % mod;
            ans = (ans + (a1 * ((l + r) * (r - l + 1) / 2) % mod)) % mod;
            ll s = ((z(r) % mod - z(l - 1) % mod) + mod) % mod;
            ans = ((ans - s1 * s % mod) + mod) % mod;
            ans = (ans + s1 * l * ((l + r) * (r - l + 1) / 2) % mod) % mod;
        }
        ans %= mod;
    }
    if (k > n)
    {
        ans = (ans + ((k - n) % mod) * n % mod) % mod;
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
