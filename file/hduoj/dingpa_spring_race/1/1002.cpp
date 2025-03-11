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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        return x = 1, y = 0, a;
    }
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}
struct mint
{
    ll x;
    mint(ll xx) : x(xx) {}
    mint operator+(mint b) { return mint((x + b.x) % mod); }
    mint operator-(mint b) { return mint((x - b.x + mod) % mod); }
    mint operator*(mint b) { return mint((x * b.x) % mod); }
    mint operator/(mint b) { return *this * invert(b); }
    mint invert(mint a)
    {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1);
        return mint((x + mod) % mod);
    }
    mint operator^(ll e)
    {
        if (!e)
        {
            return mint(1);
        }
        mint r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};
void solve()
{
    ll k;
    cin >> n >> k;
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
