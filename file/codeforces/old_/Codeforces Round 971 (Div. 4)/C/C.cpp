#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld 0x3f
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, k, x, y; // a[500005], f[500005];
void solve()
{
    cin >> x >> y >> k;
    ans = 0;
    ll s1 = ceil(1.0 * x / k);
    ll s2 = ceil(1.0 * y / k);
    if (s1 > s2)
    {
        cout << 2 * s1 - 1 << '\n';
    }
    else
    {
        cout << 2 * s2 << '\n';
    }
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
