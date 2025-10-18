/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    s3 = ' ' + s3;
    // dp[i][4] (0,12,13,23)
    vector<vector<ll>> dp(n + 10, vector<ll>(5, -1e18));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        bool f1 = 0, f2 = 0, f3 = 0;
        if (s1[i] == '1')
        {
            f1 = 1;
        }
        if (s2[i] == '1')
        {
            f2 = 1;
        }
        if (s3[i] == '1')
        {
            f3 = 1;
        }
        for (int j = 0; j <= 3; j++)
        {
            dp[i][0] = max(dp[i][0], dp[i - 1][j]);
        }
        if (f1 && f2)
        {
            dp[i][1] = max({dp[i][1], dp[i - 1][2] + 1, dp[i - 1][3] + 1, dp[i - 1][0] + 1});
        }
        if (f1 && f3)
        {
            dp[i][2] = max({dp[i][2], dp[i - 1][1] + 1, dp[i - 1][3] + 1, dp[i - 1][0] + 1});
        }
        if (f2 && f3)
        {
            dp[i][3] = max({dp[i][3], dp[i - 1][1] + 1, dp[i - 1][2] + 1, dp[i - 1][0] + 1});
        }
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';
}
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