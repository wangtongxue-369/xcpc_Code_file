#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        a[i] *= -1;
    }

    std::rotate(a.begin(), a.end() - 1, a.end());

    a.insert(a.end(), a.begin(), a.end());
    for (int i = 1; i < 2 * n; i++)
    {
        a[i] -= a[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] += a[i + n];
    }
    i64 min = *std::min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        a[i] -= min;
        a[i] /= 2;
    }
    a.resize(n);

    a.insert(a.end(), a.begin(), a.end());
    for (int i = 1; i < 2 * n; i++)
    {
        a[i] -= a[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] += a[i + n];
    }
    min = *std::min_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        a[i] -= min;
        a[i] /= 2;
    }
    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " \n"[i == n - 1];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}