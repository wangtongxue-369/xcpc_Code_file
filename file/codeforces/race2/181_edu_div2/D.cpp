/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    cin >> n >> m;
    vector<ll> l(n + 10);
    vector<ll> r(n + 10);
    vector<ll> p(n + 10);
    vector<ll> q(n + 10);
    vector<vector<array<ll, 3>>> a(m + 10);
    vector<ll> dp(m + 10);
    vector<ll> c(m + 10, 1);
    for (ll i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i] >> p[i] >> q[i];
        c[r[i]] *= (q[i] - p[i]);
        c[r[i]] %= mod;
        c[r[i]] *= ksm(q[i], mod - 2);
        c[r[i]] %= mod;
        a[l[i]].push_back({r[i], p[i], q[i]});
    }
    vector<ll> pre(m + 10, 1);
    for (int i = 1; i <= m; i++)
    {
        pre[i] = pre[i - 1] * c[i] % mod;
    }
    dp[1] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (auto [r, p, q] : a[i])
        {
            ll t = pre[r] * ksm(pre[i - 1], mod - 2) % mod;
            dp[r + 1] += (((dp[i] * p) % mod) * ksm(q - p, mod - 2) % mod) * t % mod;
            dp[r + 1] %= mod;
        }
    }
    cout << dp[m + 1] << '\n';
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