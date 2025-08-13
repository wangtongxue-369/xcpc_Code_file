#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll mod_pow(ll base, ll exp)
{
    ll result = 1;
    base %= mod;
    while (exp)
    {
        if (exp & 1)
            result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}
ll get(ll a, ll b, ll c, ll d)
{
    ll p = __gcd(a, c);
    if (b == 0 || d == 0)
    {
        return 1;
    }
    if (p == 1)
    {
        return p;
    }
    if (b > d)
    {
        swap(a, c);
        swap(b, d);
    }
    return (mod_pow(p, b) * get(a / p, b, p, d - b)) % mod;
}
void solve()
{
    ans = 1;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << get(a, b, c, d) << '\n';
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