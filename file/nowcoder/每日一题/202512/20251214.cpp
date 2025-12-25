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
    int64_t n, q;
    std::cin >> n >> q;
    std::vector<std::vector<int64_t>> a(n + 10, std::vector<int64_t>(25));
    std::vector<std::vector<int64_t>> a2(n + 10, std::vector<int64_t>(25));
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i][0];
        a2[i][0] = a[i][0];
    }
    std::vector<int64_t> lg(n + 10);
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j <= lg[n]; j++)
    {
        for (int i = 1; i <= n - (1ll << j) + 1; i++)
        {
            a[i][j] = std::max(a[i][j - 1], a[i + ((int64_t)1 << (j - 1))][j - 1]);
        }
    }
    for (int j = 1; j <= lg[n]; j++)
    {
        for (int i = 1; i <= n - (1ll << j) + 1; i++)
        {
            a2[i][j] = std::min(a2[i][j - 1], a2[i + ((int64_t)1 << (j - 1))][j - 1]);
        }
    }

    while (q--)
    {
        int64_t l, r, op;
        std::cin >> op >> l >> r;
        int64_t x = lg[r - l + 1];
        if (op == 2)
        {
            std::cout << std::max(a[l][x], a[r - ((int64_t)1 << x) + 1][x]) << '\n';
        }
        else
        {
            std::cout << std::min(a2[l][x], a2[r - ((int64_t)1 << x) + 1][x]) << '\n';
        }
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