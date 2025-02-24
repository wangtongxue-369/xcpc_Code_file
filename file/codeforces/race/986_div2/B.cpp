#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1; // n, m, ans = 0; // a[MAXN], f[MAXN];
ll ct(ll a1, ll d, ll n)
{
    if (d == 0)
    {
        // 如果公差为0，只有当a1在范围内时才有一个数
        return (a1 >= 0 && a1 <= (n - 1)) ? 1 : 0;
    }

    if (d > 0)
    {
        // 计算最大k，使得a1 + (k-1) * d <= (n-1)
        ll k = std::floor(((n - 1) - a1) / static_cast<double>(d)) + 1;
        return k;
    }
    else
    {
        // 计算最小k，使得a1 + (k-1) * d >= 0
        ll k = std::ceil((0 - a1) / static_cast<double>(d)) + 1;
        // 计算最大k，使得a1 + (k-1) * d <= (n-1)
        ll max_k = std::floor(((n - 1) - a1) / static_cast<double>(d)) + 1;
        return std::max(0ll, max_k - k + 1);
    }
}
void solve()
{
    ll n, b, c;
    cin >> n >> b >> c;
    if (b == 0)
    {
        if (c < n - 2)
        {
            cout << -1 << '\n';
            return;
        }
        if (c < n)
        {
            cout << n - 1 << '\n';
            return;
        }
        cout << n << '\n';
        return;
    }
    if (n <= c)
    {
        cout << n << '\n';
        return;
    }
    ll z = (n - c + b - 1) / b;
    cout << n - 1 - max(0ll, n - c - 1) / b << '\n';
    // ll d = b;
    // if (b == 0 && c == 0)
    // {
    //     cout << -1 << '\n';
    //     return;
    // }
    // if (d == 0)
    // {
    //     if (c <= n)
    //     {
    //         cout << n - 1 << '\n';
    //         return;
    //     }
    //     else
    //     {
    //         cout << n << '\n';
    //         return;
    //     }
    // }
    // ll a1 = c;
    // ll k;
    // cout << min(max(0ll, n - ct(c, d, n)), n) << '\n';
    // if (d < 0)
    // {
    //     if ()
    //     k = a1 / d;
    //     cout << n - k << '\n';
    //     return;
    // }
    // else
    // {
    //     k = (n - a1) / d;
    //     cout << n - k << '\n';
    //     return;
    // }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
