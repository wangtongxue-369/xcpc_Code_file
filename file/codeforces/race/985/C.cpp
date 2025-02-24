#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 300005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
ll dp[MAXN][2];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll maxn1 = 0, maxn0 = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][0];
        if (dp[i][0] > a[i])
        {
            dp[i][0]--;
        }
        else if (dp[i][0] < a[i])
        {
            dp[i][0]++;
        }
        if (i == 1)
        {
            continue;
        }
        ll op1 = dp[i - 1][1];
        if (op1 > a[i])
        {
            op1--;
        }
        else if (op1 < a[i])
        {
            op1++;
        }

        dp[i][1] = max(op1, maxn0);
        // if (dp[i][1] == 6)
        // {
        //     cout << '!' << i << ' ' << dp[i - 1][1] << ' ' << maxn0 << '\n';
        // }
        maxn0 = max(maxn0, dp[i][0]);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i][0] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dp[i][1] << ' ';
    // }
    // cout << '\n';
    cout << dp[n][1] << '\n';
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
