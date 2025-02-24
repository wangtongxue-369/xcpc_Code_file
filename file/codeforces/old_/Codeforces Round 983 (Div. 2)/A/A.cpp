#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll sum1 = 0, sum0 = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            sum1++;
        }
        else
        {
            sum0++;
        }
    }
    cout << sum1 % 2 << ' ' << min(sum1, 2 * n - sum1) << '\n';
    // if (sum1 < sum0)
    // {
    //     cout << sum1 << '\n';
    // }
    // else
    // {
    //     cout <<  << '\n';
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
