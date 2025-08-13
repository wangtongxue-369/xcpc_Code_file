#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll l, r, k;
    cin >> n >> l >> r >> k;
    if (n % 2 == 1)
    {
        cout << l << '\n';
        return;
    }
    ll p = 64;
    for (int i = 0; i <= 64; i++)
    {
        if ((1ll << i) > l)
        {
            p = i;
            break;
        }
    }
    if ((1ll << p) > r)
    {
        cout << -1 << '\n';
        return;
    }
    if (n == 2)
    {
        cout << -1 << '\n';
        return;
    }
    if (k <= n - 2)
    {
        cout << l << '\n';
    }
    else
    {
        cout << (1ll << p) << '\n';
    }
}
// 一边是所有的都要存在，一边是需要奇数个
// 首先最小的可能是 全部都是l
// 但是如果n是偶数呢
// 那就尝试换
//
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}