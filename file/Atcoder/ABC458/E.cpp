/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
const ll MOD = 998244353;

ll modpow(ll a, ll e)
{
    ll r = 1;
    while (e > 0)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

struct Comb
{
    vector<ll> fact, invfact;

    Comb(int n)
    {
        fact.resize(n + 1);
        invfact.resize(n + 1);

        fact[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        invfact[n] = modpow(fact[n], MOD - 2);
        for (int i = n; i >= 1; i--)
        {
            invfact[i - 1] = invfact[i] * i % MOD;
        }
    }

    ll C(int n, int r) const
    {
        if (r < 0 || r > n)
            return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    }
};
void solve()
{
    ll x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int a = x1;
    int b = x2;
    int c = x3;

    int N = b + 1;

    int maxn = max({N, a - 1, N + c - 1}) + 5;

    Comb comb(maxn);

    ll ans = 0;

    int m = min(a, N);

    for (int i = 1; i <= m; i++)
    {
        ll tmp = 1;
        tmp = tmp * comb.C(N, i) % mod;
        tmp = tmp * comb.C(a - 1, i - 1) % mod;
        tmp = tmp * comb.C(N - i + c - 1, c) % mod;

        ans += tmp;
        ans %= mod;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}