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
    int64_t n, l, r;
    std::cin >> n >> l >> r;
    std::string s;
    std::cin >> s;
    s = ' ' + s;
    std::vector<std::vector<int64_t>> ve(n + 10);
    for (int i = 1; i < n; i++)
    {
        int64_t u, v;
        std::cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    int64_t ans = 0;
    std::function<void(int64_t x, int64_t sp, int64_t fa, int64_t cnt)> dfs = [&](int64_t x, int64_t sp, int64_t fa, int64_t cnt)
    {
        if (sp > r)
        {
            return;
        }
        if (l <= sp && sp <= r && cnt > 1)
        {
            ans++;
        }
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            dfs(it, sp * 2 + s[it] - '0', x, cnt + 1);
        }
    };
    for (int i = 1; i <= n; i++)
    {
        dfs(i, s[i] - '0', 0, 1);
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