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
#define ll long long
ll _ = 1, n, m, c;
void solve()
{
    // n 传教士 m 野人 c 容量
    std::cin >> n >> m >> c;
    std::map<std::array<ll, 5>, std::vector<std::array<ll, 7>>> ma;
    ma[{n, m, 0, 0, 0}] = std::vector<std::array<ll, 7>>(0);
    std::queue<std::pair<std::array<ll, 5>, std::vector<std::array<ll, 7>>>> q;
    q.push({{n, m, 0, 0, 0}, std::vector<std::array<ll, 7>>(0)});
    while (!q.empty())
    {
        auto fro = q.front().first;
        auto ve = q.front().second;
        auto n1 = fro[0], m1 = fro[1], n2 = fro[2], m2 = fro[3], p = fro[4];
        q.pop();
        if (p == 0)
        {
            for (int i = 0; i <= n1; i++)
            {
                for (int j = 0; j <= m1; j++)
                {
                    if (i + j == 0 || i + j > c)
                    {
                        continue;
                    }
                    ll ln1 = n1 - i, lm1 = m1 - j;
                    ll rn2 = n2 + i, rm2 = m2 + j;
                    if ((ln1 > 0 && ln1 < lm1) || (rn2 > 0 && rn2 < rm2))
                    {
                        continue;
                    }
                    std::array<ll, 5> key = {ln1, lm1, rn2, rm2, 1};
                    auto it = ma.find(key);
                    if (it != ma.end() && ve.size() + 1 >= it->second.size())
                    {
                        continue;
                    }
                    auto nve = ve;
                    nve.push_back({1, i, j, ln1, lm1, rn2, rm2});
                    ma[key] = nve;
                    q.push({key, nve});
                }
            }
        }
        else
        {
            for (int i = 0; i <= n2; i++)
            {
                for (int j = 0; j <= m2; j++)
                {
                    if (i + j > c)
                    {
                        continue;
                    }
                    ll ln1 = n1 + i, lm1 = m1 + j;
                    ll rn2 = n2 - i, rm2 = m2 - j;
                    if ((ln1 > 0 && ln1 < lm1) || (rn2 > 0 && rn2 < rm2))
                    {
                        continue;
                    }
                    std::array<ll, 5> key = {ln1, lm1, rn2, rm2, 0};
                    auto it = ma.find(key);
                    if (it != ma.end() && ve.size() + 1 >= it->second.size())
                    {
                        continue;
                    }
                    auto nve = ve;
                    nve.push_back({0, i, j, ln1, lm1, rn2, rm2});
                    ma[key] = nve;
                    q.push({key, nve});
                }
            }
        }
    }
    // std::cout << "!!";
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //     {
    //         std::cout << ma[{n - i, m - j, i, j, 0}].size() << ' ';
    //     }
    //     std::cout << '\n';
    // }
    for (auto [f, i, j, n1, m1, n2, m2] : ma[{0, 0, n, m, 1}])
    {

        if (f)
        {
            std::cout << "move " << i << " 传教士 and " << j << " 野人 from left to right \n";
            std::cout << "现在左边有 " << n1 << "个 传教士 " << m1 << "个野人 " << "右边有 " << n2 << " 个传教士 " << "右边有 " << m2 << "个野人\n";
        }
        else
        {
            std::cout << "move " << i << " 传教士 and " << j << " 野人 from right to left \n";
            std::cout << "现在左边有 " << n1 << "个 传教士 " << m1 << "个野人 " << "右边有 " << n2 << " 个传教士 " << "右边有 " << m2 << "个野人\n";
        }
    }
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}