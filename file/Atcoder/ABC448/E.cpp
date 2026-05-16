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
const ll mod = 1e4 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, c[MAXN], l[MAXN];
ll ksm(ll a, ll b, ll modd)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % modd;
        }
        a = a * a % modd;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll k;
    cin >> k >> m;
    ll maxn = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> c[i] >> l[i];
        maxn = max(maxn, l[i]);
    }
    ll mod2 = m * mod;
    ll x = 0;
    for (int i = 1; i <= k; i++)
    {
        ll p1 = ksm(10, l[i], mod2);
        ll p2 = ksm(9, mod2 - 2, mod2);
        ll p3 = (p1 - 1) * p2 % mod2;
        x = ((__int128_t)x * p1) % mod2 + ((__int128_t)c[i] * p3 % mod2) % mod2;
    }
    ll res = x % m;
    cout << (((x - res) / m) % mod + mod) % mod;
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