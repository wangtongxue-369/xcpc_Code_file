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
    std::vector<std::vector<std::pair<int64_t, int64_t>>> ve(n + 10);
    std::vector<std::vector<std::pair<int64_t, int64_t>>> ve2(n + 10);
    int64_t u, v, w;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve2[v].push_back({u, w});
    }
    std::vector<int64_t> d(n + 10, 1e18);
    std::priority_queue<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, std::greater<std::pair<int64_t, int64_t>>> q;
    d[1] = 0, q.push({0, 1});
    while (!q.empty())
    {
        auto [c, x] = q.top();
        q.pop();
        if (d[x] < c)
        {
            continue;
        }
        for (auto [it, t] : ve[x])
        {
            if (c + t < d[it])
            {
                d[it] = c + t;
                q.push({c + t, it});
            }
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= n; i++)
    {
        // std::cout << d[i] << " ";
        ans += d[i];
    }
    // std::cout << ans << '\n';
    std::vector<int64_t> d2(n + 10, 1e18);
    q = std::priority_queue<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, std::greater<std::pair<int64_t, int64_t>>>();
    d2[1] = 0, q.push({0, 1});
    while (!q.empty())
    {
        auto [c, x] = q.top();
        q.pop();
        if (d2[x] < c)
        {
            continue;
        }
        for (auto [it, t] : ve2[x])
        {
            if (c + t < d2[it])
            {
                d2[it] = c + t;
                q.push({c + t, it});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans += d2[i];
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