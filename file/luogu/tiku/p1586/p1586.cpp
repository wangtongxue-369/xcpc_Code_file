#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
ll dp[32778][5];
// dp[i][j] 考虑到i数字时，答案为j的方案数;
void init()
{
    dp[0][0] = 1;
    for (int i = 1; i * i <= 32768; i++)
    {
        for (int j = 1; j <= 32768; j++)
        {
            for (int k = 1; k <= 4; k++)
            {
                if (j - (i * i) >= 0)
                {
                    dp[j][k] += dp[j - i * i][k - 1];
                }
            }
        }
    }
    // cout << dp[185][25][4] << '\n';
}
void solve()
{
    cin >> n;
    ans = 0;
    for (int k = 1; k <= 4; k++)
    {
        ans += dp[n][k];
    }
    cout << ans << '\n';
    // cout << dp[185][n][1] + dp[185][n][2] + dp[185][n][3] + dp[185][n][4] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
