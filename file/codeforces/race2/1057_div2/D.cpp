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
    vector<ll> dp(n + 10);
    vector<ll> ve(n + 10); // ve2(n + 10), ve3(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ve[i] = a[i];
        dp[i] = 1e18;
    }
    ans = 1e18;
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i - 2 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 2] + abs(ve[i - 1] - ve[i]));
        }
        if (i - 3 >= 0)
        {
            dp[i] = min({dp[i], dp[i - 3] + abs(ve[i] - ve[i - 1]) + abs(ve[i] - ve[i - 2]), dp[i - 3] + abs(ve[i - 1] - ve[i]) + abs(ve[i - 1] - ve[i - 2]),
                         dp[i - 3] + abs(ve[i - 2] - ve[i]) + abs(ve[i - 2] - ve[i - 1])});
        }
        // cout << dp[i] << '\n';
    }
    ans = min(ans, dp[n]);

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e18;
        if (i + 1 > n)
        {
            ve[(i + 1) % n] = a[i];
        }
        else
        {
            ve[i + 1] = a[i];
        }
    }
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i - 2 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 2] + abs(ve[i - 1] - ve[i]));
        }
        if (i - 3 >= 0)
        {
            dp[i] = min({dp[i], dp[i - 3] + abs(ve[i] - ve[i - 1]) + abs(ve[i] - ve[i - 2]), dp[i - 3] + abs(ve[i - 1] - ve[i]) + abs(ve[i - 1] - ve[i - 2]),
                         dp[i - 3] + abs(ve[i - 2] - ve[i]) + abs(ve[i - 2] - ve[i - 1])});
        }
    }
    ans = min(ans, dp[n]);
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1e18;
        if (i + 2 > n)
        {
            ve[(i + 2) % n] = a[i];
        }
        else
        {
            ve[i + 2] = a[i];
        }
    }
    dp[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (i - 2 >= 0)
        {
            dp[i] = min(dp[i], dp[i - 2] + abs(ve[i - 1] - ve[i]));
        }
        if (i - 3 >= 0)
        {
            dp[i] = min({dp[i], dp[i - 3] + abs(ve[i] - ve[i - 1]) + abs(ve[i] - ve[i - 2]), dp[i - 3] + abs(ve[i - 1] - ve[i]) + abs(ve[i - 1] - ve[i - 2]),
                         dp[i - 3] + abs(ve[i - 2] - ve[i]) + abs(ve[i - 2] - ve[i - 1])});
        }
    }
    ans = min(ans, dp[n]);
    cout << ans << '\n';
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