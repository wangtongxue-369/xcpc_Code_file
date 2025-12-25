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
    int64_t n;
    int64_t x1, y1, x2, y2;
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    int s1 = std::abs(x1 - 2) + std::abs(n - y1);
    int s2 = std::abs(x2 - 2) + std::abs(n - y2);
    // std::cout << s1 << ' ' << s2 << '\n';
    if (s1 == s2)
    {
        std::cout << "YES\n";
        return;
    }
    if (x1 == 2 && y1 == n && x2 == 2 && y2 == n)
    {
        std::cout << "YES\n";
        return;
    }
    if (x1 == 2 && y1 == n)
    {
        std::cout << "NO\n";
        return;
    }
    if (x2 == 2 && y2 == n)
    {
        std::cout << "NO\n";
        return;
    }
    if (x1 == x2)
    {
        if (y1 == y2)
        {
            std::cout << "YES\n";
        }
        else
        {
            std::cout << "NO\n";
        }
        return;
    }
    if (x2 == 1)
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    int64_t c = abs(y2 - y1);
    if (y2 + 1 < n && c == 1)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }

    // // if (y1 < y2)
    // {
    //     int64_t c = abs(y2 - y1 - 1);
    //     //std::cout << c << '\n';
    //     if (c % 2 == 0 && (n - std::min(y1, y2)) / 2 >= c / 2)
    //     {
    //         std::cout << "YES\n";
    //     }
    //     else
    //     {
    //         std::cout << "NO\n";
    //     }
    // }
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