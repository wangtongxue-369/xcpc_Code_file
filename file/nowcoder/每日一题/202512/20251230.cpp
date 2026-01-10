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
    std::vector<int64_t> ve;
    std::vector<std::array<int64_t, 3>> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
        ve.push_back(a[i][0]);
        ve.push_back(a[i][1]);
    }
    sort(ve.begin(), ve.end());
    int64_t cnt = std::unique(ve.begin(), ve.end()) - ve.begin();
    for (int i = 1; i <= n; i++)
    {
        a[i][0] = std::lower_bound(ve.begin(), ve.begin() + cnt, a[i][0]) - ve.begin();
        a[i][1] = std::lower_bound(ve.begin(), ve.begin() + cnt, a[i][1]) - ve.begin();
    }
    std::vector<int64_t> fa(cnt + 10);
    std::function<int64_t(int64_t x)> find = [&](int64_t x)
    {
        if (fa[x] != x)
        {
            return fa[x] = find(fa[x]);
        }
        return fa[x];
    };
    std::function<void(int64_t x, int64_t y)> unio = [&](int64_t x, int64_t y)
    {
        x = find(x);
        y = find(y);
        if (x != y)
        {
            fa[y] = x;
        }
    };
    for (int i = 0; i <= cnt + 1; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i][2] == 1)
        {
            unio(a[i][0], a[i][1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i][2] == 0 && find(a[i][0]) == find(a[i][1]))
        {
            std::cout << "NO\n";
            return;
        }
    }
    std::cout << "YES\n";
    return;
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