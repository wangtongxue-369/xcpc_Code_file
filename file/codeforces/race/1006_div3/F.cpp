#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll p = 2;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1; // n, m, ans = 0, a[MAXN], f[1000][1000];
ll pow_quick(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % p;
        }
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
ll C(ll n, ll m)
{
    if (m > n)
    {
        return 0;
    }
    ll ans = 1;
    for (ll i = 1; i <= m; i++)
    {
        ll a = (n + i - m) % p;
        ll b = i % p;
        ans = (ans * (a * pow_quick(b, p - 2) % p)) % p;
    }
    return ans;
}
ll Lucas(ll n, ll m)
{
    if (m == 0)
    {
        return 1;
    }
    else
    {
        return (C(n % p, m % p) * Lucas(n / p, m / p)) % p;
    }
}
void solve()
{
    ll k, n;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        if (((n - 1) & i) == i)
        {
            cout << k << ' ';
        }
        else
        {
            cout << 0 << ' ';
        }
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Lucas(1e6 + 1, 1e6 + 1);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
