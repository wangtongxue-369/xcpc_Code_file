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
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &it : a)
    {
        std::cin >> it;
    }
    int x;
    std::cin >> x;
    int t = 0;
    std::vector<int> ve;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > x)
        {
            ve.push_back(i);
        }
    }
    reverse(ve.begin(), ve.end());
    int s = -1, p = n;
    while (s < p)
    {
        if (ve.size() && ve.back() > s)
        {
            p = ve.back();
            ve.pop_back();
        }
        s++;
        t++;
    }
    std::cout << t << '\n';
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