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
    int64_t n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    int64_t cnt1 = 0, cnt0 = 0;
    int64_t l = 0, sum = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;
            sum += cnt0;
        }
        if (sum == k)
        {
            std::cout << l + 1 << ' ' << i + 1 << '\n';
            return;
        }
        while (sum > k)
        {
            if (s[l] == '1')
            {
                cnt1--;
            }
            else
            {
                sum -= cnt1;
                cnt0--;
            }
            l++;
            if (sum == k)
            {
                std::cout << l + 1 << ' ' << i + 1 << '\n';
                return;
            }
        }
    }
    std::cout << "-1\n";
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