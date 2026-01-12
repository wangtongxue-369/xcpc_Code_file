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
    std::cin >> n;
    std::vector<int64_t> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + 1 + n, std::greater<int64_t>());
    if (a[1] > n)
    {
        std::cout << "-1\n";
        return;
    }
    int64_t ans = 1;
    int64_t sum = 0, pi = 1;
    std::reverse(a.begin() + 1, a.begin() + 1 + n);
    for (int i = 1; i <= n - a[n]; i++)
    {
        sum++;
        if (sum >= a[i])
        {
            ans++;
            sum = 0;
        }
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