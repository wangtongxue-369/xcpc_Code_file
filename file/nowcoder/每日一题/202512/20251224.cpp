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
void solve()
{
    int n, k;
    std::cin >> n >> k;
    std::vector<int64_t> a(n + 1);
    std::vector<int64_t> b(n + 1);
    std::vector<std::array<int64_t, 2>> dp(n + 10);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }
    dp[0][1] = -1e18;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i];
        dp[i][1] = dp[i - 1][1] + b[i];
        if (dp[i - 1][0] >= k)
        {
            dp[i][1] = std::max(dp[i][1], dp[i - 1][0] - k + b[i]);
        }
        if (dp[i - 1][1] >= k)
        {
            dp[i][0] = std::max(dp[i][0], dp[i - 1][1] - k + a[i]);
        }
    }
    std::cout << std::max(dp[n][1], dp[n][0]) << '\n';
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