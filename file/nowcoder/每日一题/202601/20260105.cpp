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
    int64_t n, h, k;
    std::cin >> n >> h >> k;
    std::vector<std::pair<int64_t, int64_t>> a(n);
    for (auto &it : a)
    {
        std::cin >> it.first;
    }
    for (auto &it : a)
    {
        std::cin >> it.second;
    }
    std::vector<int64_t> dp(n + 10);
    std::sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int64_t ans = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i].first >= h || a[i].second >= k)
        {
            continue;
        }
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j].first > a[i].first && a[j].second > a[i].second)
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        ans = std::max(ans, dp[i]);
    }
    std::cout << ans << '\n';
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