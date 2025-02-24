#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a, b; // a[500005], f[500005];
void solve()
{
    cin >> n >> a >> b;
    // ll sum = 0;
    ll sum0 = 0, sum1 = 1, sumf = 0;
    for (int i = 1; i <= n; i++)
    {
        ll sum = (n - i + 2) * (n - i + 1);
        sum -= ((max(n - i + 1, (ll)i)) - i + 1 + n - i + 1) * (n - max(n - i + 1, (ll)i) + 1) / 2;
        ans += sum;
    }
    // cout << ans << '\n';
    for (int i = 1; i <= a; i++)
    {
        ll len = min(a, b + i - 1) - max(b - i + 1, 1ll) + 1;
        len = len - i + 1;
        if (a + i <= n)
        {
            len *= 2;
        }
        ans -= len;
        // if (b + i - 1 <= a)
        // {
        //     ans--;
        //     if (a + i <= n)
        //     {
        //         ans--;
        //     }
        // }
        // if (b - i + 1 >= 1)
        // {
        //     ans--;
        //     if (a - i >= 1)
        //     {
        //         ans--;
        //     }
        // }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
