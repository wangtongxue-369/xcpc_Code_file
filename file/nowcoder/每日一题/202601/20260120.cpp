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
void solve()
{
    int64_t n;
    std::cin >> n;
    std::vector<int64_t> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    if (n == 1)
    {
        for (int i = 0; i <= 9; i++)
        {
            if (a[1] == i)
            {
                std::cout << 1 << ' ';
            }
            else
            {
                std::cout << 0 << ' ';
            }
        }
        std::cout << '\n';
        return;
    }
    std::vector<std::vector<int64_t>> dp(n + 10, std::vector<int64_t>(12));
    dp[n][a[n] % 10] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j <= 9; j++)
        {
            dp[i][(j + a[i]) % 10] += dp[i + 1][j];
            dp[i][(j + a[i]) % 10] %= mod;
            dp[i][j * a[i] % 10] += dp[i + 1][j];
            dp[i][j * a[i] % 10] %= mod;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        std::cout << dp[1][i] << " ";
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