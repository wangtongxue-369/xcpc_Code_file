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
    int64_t n, t;
    int64_t to1, to2;
    std::cin >> n >> t >> to1 >> to2;
    std::vector<int64_t> a(n + 10);
    std::vector<int64_t> b(n + 10);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        std::cin >> b[i];
    }
    int64_t ans1 = 0, ans2 = 0;
    int64_t sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] >= to1)
        {
            continue;
        }
        if (sum + a[i] <= t)
        {
            sum += a[i];
            ans1++;
        }
    }
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] >= to2)
        {
            if (sum + 2 * a[i] <= t)
            {
                sum += 2 * a[i];
                ans2++;
            }
            continue;
        }
        if (sum + a[i] <= t)
        {
            sum += a[i];
            ans2++;
        }
    }
    std::cout << ans1 << ' ' << ans2 << '\n';
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