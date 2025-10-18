/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<vector<ll>> dp(n + 10, vector<ll>(2, 0));
    dp[1][0] = 1; // buhuan
    dp[1][1] = 1; // huan

    for (int i = 2; i <= n; i++)
    {
        if (a[i - 1] <= a[i] && b[i - 1] <= b[i])
        {
            dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
            dp[i][1] = (dp[i][1] + dp[i - 1][1]) % mod;
        }
        if (a[i - 1] <= b[i] && b[i - 1] <= a[i])
        {
            dp[i][0] = (dp[i][0] + dp[i - 1][1]) % mod;
            dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % mod << '\n';
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