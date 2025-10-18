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
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, k, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll H, h, T, t, K, k;
    cin >> H >> T;
    cin >> n;
    vector<array<ll, 3>> ve(n);
    for (auto &[s1, s2, s3] : ve)
    {
        cin >> s1 >> s2 >> s3;
    }
    vector<vector<vector<ll>>> dp(n + 10, vector<vector<ll>>(H + 10, vector<ll>(T + 10)));
    ll p = 1;
    for (auto &[h, t, k] : ve)
    {
        for (int i = H; i > 0; i--)
        {
            for (int j = T; j > 0; j--)
            {
                dp[p][i][j] = dp[p - 1][i][j];
                if (i - h >= 0 && j - t >= 0)
                {
                    dp[p][i][j] = max(dp[p][i][j], dp[p - 1][i - h][j - t] + k);
                    ans = max(ans, dp[p][i][j]);
                }
            }
        }
        p++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}