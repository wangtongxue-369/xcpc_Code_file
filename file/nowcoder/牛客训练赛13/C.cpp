#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;

const ll base1 = 131;
const ll base2 = 127;
ll _ = 1; // n, m, ans = 0;// a[MAXN], f[MAXN];

const ll MAXN = 1e7 + 5;
ll p = mod;
ll fact[MAXN];
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
void getfact()
{
    fact[0] = 1;
    for (ll i = 1; i < MAXN; i++)
    {
        fact[i] = i * fact[i - 1] % p;
    }
}
ll get_inv(ll a)
{
    return pow_quick(a, p - 2);
}
ll C(ll n, ll m)
{
    if (m > n)
    {
        return 0;
    }
    return fact[n] * get_inv(fact[n - m] * fact[m] % p) % p;
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    if (n % 2 == 1 || k < 2)
    {
        cout << 0 << '\n';
        return;
    }
    if (n / 2 < k)
    {
        cout << C(n, k) << '\n';
        return;
    }
    cout << ((C(n, k) - C(n / 2, k) * pow_quick(2, k) % mod) + mod) % mod << '\n';
    // cout << ((n / 2) * C(n - 2, k - 2) % mod) << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    getfact();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
