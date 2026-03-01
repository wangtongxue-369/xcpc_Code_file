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
const int64_t mod = 1e9 + 7;
int64_t ksm(int64_t a, int64_t b)
{
    int64_t ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}
int64_t C(int64_t n, int64_t m)
{
    if (m > n)
    {
        return 0;
    }
    int64_t ans = 1;
    for (int64_t i = 1; i <= m; i++)
    {
        int64_t a = (n + i - m) % mod;
        int64_t b = i % mod;
        ans = (ans * (a * ksm(b, mod - 2) % mod)) % mod;
    }
    return ans;
}
int64_t Lucas(int64_t n, int64_t m)
{
    if (m == 0)
    {
        return 1;
    }
    return (C(n % mod, m % mod) * Lucas(n / mod, m / mod)) % mod;
}
void solve()
{
    int64_t n, m;
    std::cin >> n;
    std::vector<int64_t> a(n + 10);
    int64_t pre = 1000, n0 = 0;
    int64_t ans = 1;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        if (a[i] == 0)
        {
            n0++;
            continue;
        }
        if (n0 != 0)
        {
            int64_t w = pre - a[i] + 1;
            ans *= Lucas(n0 + w - 1, w - 1);
            ans %= mod;
            n0 = 0;
        }
        pre = a[i];
        // std::cout << ans << '\n';
    }
    if (n0 != 0)
    {
        ans *= Lucas(n0 + pre - 1, pre - 1);
        ans %= mod;
    }
    std::cout << ans << '\n';

    // C(len,d)
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