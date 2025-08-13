#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], b[N], dp[1010][6010];
void solve()
{
    memset(dp, INF, sizeof(dp));
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }
    dp[0][0] = 0;
    // dp[i][j] 考虑到i时，上面和为j时的最小操作数
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n * 6; j++)
        {
            if (j - a[i] >= 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
            }
            if (j - b[i] >= 0)
            {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + 1);
            }
        }
    }
    ll d = 1e10, s1 = 0;
    ;
    ans = 1e10;
    // cout << sum << '\n';
    for (int j = 1; j <= n * 6; j++)
    {
        // if (dp[n][j] >= 1e10)
        // {
        //     cout << -1 << ' ';
        // }
        // else
        // {
        //     cout << dp[n][j] << " ";
        // }
        if (dp[n][j] >= 1e10)
        {
            continue;
        }
        if (abs(abs(sum - j) - j) < d)
        {
            ans = dp[n][j];
            s1 = j;
            d = abs(abs(sum - j) - j);
        }
        if (abs(abs(sum - j) - j) == d)
        {
            // if (dp[n][j] < ans)
            // {
            //     s1 = j;
            // }
            ans = min(ans, dp[n][j]);
        }
    }
    // cout << '\n';
    cout << ans << '\n'; // << s1 << '\n';
    // cout << dp[n][s1] << '\n';
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
