#include <bits/stdc++.h>
using ll = long long;
bool cmp(long double x, long double y)
{
    return x > y;
}
void solve()
{
    int n;
    std::cin >> n;
    std::vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> c[i];
    }
    std::sort(c.begin(), c.end());
    ll l = -2e18, r = 2e18;
    auto check = [&](ll y) -> bool
    {
        ll cnt = 0;
        std::vector<long double> x1, x2;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                long double x = (long double)(y - b[i]) / a[i];
                x1.push_back(x);
            }
            else if (a[i] < 0)
            {
                long double x = (long double)(y - b[i]) / a[i];
                x2.push_back(x);
            }
            else
            {
                cnt += (b[i] >= y);
            }
        }
        std::sort(x1.begin(), x1.end(), cmp);
        std::sort(x2.begin(), x2.end());
        int id = 0;
        for (auto it : x2)
        {
            if (it >= c[id])
            {
                id++;
                cnt++;
            }
        }
        id = n - 1;
        for (auto it : x1)
        {
            if (it <= c[id])
            {
                id--;
                cnt++;
            }
        }
        return (cnt >= (n + 1) / 2);
    };
    ll ans = 0;
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << ans << "\n";
}
int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--)
        solve();
    return 0;
}