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
const long double pi = acos(-1);
void solve()
{
    int64_t n, k;
    std::cin >> n >> k;
    long double ans = 0;
    long double x, y, r;
    std::vector<long double> ve;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x >> y >> r;
        long double d = std::max((long double)0, r - sqrt(x * x + y * y));
        if (d <= 0)
        {
            continue;
        }
        ve.push_back(pi * r * r * d);
    }
    std::sort(ve.begin(), ve.end(), std::greater<long double>());
    while (ve.size() > k)
    {
        ans += ve.back();
        ve.pop_back();
    }
    std::cout << std::fixed << std::setprecision(8) << ans << '\n';
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