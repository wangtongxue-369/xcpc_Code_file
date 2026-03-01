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
int64_t dp[(1 << 16) + 10][18][4];
void solve()
{
    int64_t n;
    std::cin >> n;
    std::vector<std::vector<int64_t>> p(n + 2, std::vector<int64_t>(n + 2));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> p[i][j];
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    // dp[状态下][当前位置][]

    for (int i = 0; i < n; i++)
    {
        dp[(1ll << i)][i][0] = 0;
    }
    for (int i = 0; i < (1ll << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i & (1ll << j)) == 0)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if (i & (1ll << k))
                {
                    continue;
                }
                int64_t x = i | (1ll << k);
                dp[x][k][0] = std::min({dp[x][k][0], dp[i][j][0] + p[j][k]});
                dp[x][k][1] = std::min({dp[x][k][1], dp[i][j][0] + 0, dp[i][j][1] + p[j][k]});
                dp[x][k][2] = std::min({dp[x][k][2], dp[i][j][0] + 2 * p[j][k], dp[i][j][2] + p[j][k]});
                dp[x][k][3] = std::min({dp[x][k][3], dp[i][j][1] + 2 * p[j][k], dp[i][j][2], dp[i][j][3] + p[j][k]});
            }
        }
    }
    int64_t ans = 1e18;
    for (int i = 0; i < n; i++)
    {
        ans = std::min(ans, dp[(1 << (n)) - 1][i][3]);
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