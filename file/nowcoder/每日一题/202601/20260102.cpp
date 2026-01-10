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
    int64_t n, k;
    std::cin >> n >> k;
    std::vector<int64_t> a(n + 10);
    int64_t sum = 0;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
        sum += a[i];
    }
    if (sum < k)
    {
        std::cout << 0 << '\n';
        return;
    }
    std::function<bool(int64_t x)> check = [&](int64_t x)
    {
        int64_t sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i] / x;
        }
        return sum >= k;
    };
    int64_t l = 1, r = 1e10;
    while (l < r)
    {
        int64_t mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << l << '\n';
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