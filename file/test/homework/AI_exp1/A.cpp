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
ll _ = 1, n, m;
// 0
// 1 box
// 2 monkbnay
// 3 banana
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};
void solve()
{
    std::cin >> n >> m;
    std::vector<std::vector<ll>> a(n + 10, std::vector<ll>(m + 10));
    ll monx, mony, bnax, bnay, boxx, boxy;
    // 输入
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == 1)
            {
                boxx = i, boxy = j;
            }
            else if (a[i][j] == 2)
            {
                monx = i, mony = j;
            }
            else if (a[i][j] == 3)
            {
                bnax = i, bnay = j;
            }
        }
    }
    // 构造操作序列
    // monx,mony,boxx,boxy,ison
    std::map<std::array<ll, 5>, std::vector<std::string>> ma;
    ma[{monx, mony, boxx, boxy, 0}] = std::vector<std::string>(0);
    std::queue<std::pair<std::array<ll, 3>, std::vector<std::string>>> q;
    std::string s = "monkey walk from ( " + std::to_string(monx) + "," + std::to_string(mony) + " ) to ( " + std::to_string(boxx) + "," + std::to_string(boxy) + " ) \n" + "now monkey at ( " + std::to_string(boxx) + "," + std::to_string(boxy) + " ) box at ( " + std::to_string(boxx) + "," + std::to_string(boxy) + " )\n";
    q.push({{boxx, boxy, 0}, std::vector<std::string>(1, s)});
    ma[{boxx, boxy, boxx, boxy, 0}] = std::vector<std::string>(1, s);
    while (!q.empty()) // BFS所有状态
    {
        auto fro = q.front().first;
        auto ve = q.front().second;
        auto x = fro[0], y = fro[1], ison = fro[2];
        q.pop();
        if (ve.size() > ma[{x, y, x, y, ison}].size())
        {
            continue;
        }
        if (ison == 1)
        {
            if (ma.count({x, y, x, y, 0}) == 0)
            {
                ve.push_back("monkey come down from the box\n");
                ma[{x, y, x, y, 0}] = ve;
                q.push({{x, y, 0}, ve});
            }
            continue;
        }
        if (ma.count({x, y, x, y, 1}) == 0)
        {
            ve.push_back("monkey get up from the box\n");
            ma[{x, y, x, y, 1}] = ve;
            q.push({{x, y, 1}, ve});
            ve.pop_back();
        }
        for (int i = 0; i < 4; i++)
        {
            ll xx = x + dx[i];
            ll yy = y + dy[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
            {
                if (ma.count({xx, yy, xx, yy, 1}))
                {
                    continue;
                }
                std::string s = "monkey walk and push box from ( " + std::to_string(x) + "," + std::to_string(y) + " ) to ( " +
                                std::to_string(xx) + "," + std::to_string(yy) + " ) \n" +
                                "now monkey at ( " + std::to_string(xx) + "," + std::to_string(yy) +
                                " ) box at ( " + std::to_string(xx) + "," + std::to_string(yy) + " )\n";
                ve.push_back(s);
                ma[{xx, yy, xx, yy, 0}] = ve;
                q.push({{xx, yy, 0}, ve});
                ve.pop_back();
            }
        }
    }
    // 输出结果时的状态
    for (auto it : ma[{bnax, bnay, bnax, bnay, 1}])
    {
        std::cout << it;
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