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
    int64_t n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int64_t>> a(n + 10, std::vector<int64_t>(n + 10));
    for (int i = 1; i <= m; i++)
    {
        int64_t x, y;
        std::cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    int64_t t = 0, l = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (a[i][j] && a[j][k] && a[i][k])
                {
                    l += 3;
                    t++;
                }
                else if (a[i][j] && a[i][k] || a[i][j] && a[j][k] || a[i][k] && a[j][k])
                {
                    l++;
                }
            }
        }
    }
    t *= 3;
    if (t == 0)
    {
        std::cout << "0/1\n";
    }
    else
    {
        std::cout << t / std::__gcd(t, l) << "/" << l / std::__gcd(t, l) << '\n';
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}