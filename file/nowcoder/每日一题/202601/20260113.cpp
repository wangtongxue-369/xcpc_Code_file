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
#define ll long long
const ll mod = 1e9 + 7;
ll ksm(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a;
            ans %= mod;
        }
        a = a * a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
void solve()
{
    ll n, q;
    std::cin >> n >> q;
    std::vector<ll> a(n + 10);
    a[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        a[i] *= a[i - 1];
        a[i] %= mod;
    }
    while (q--)
    {
        ll l, r;
        std::cin >> l >> r;
        std::cout << a[r] * ksm(a[l - 1], mod - 2) << ' ';
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}