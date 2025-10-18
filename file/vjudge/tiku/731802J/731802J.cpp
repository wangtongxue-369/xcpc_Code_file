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
const ll MAXN = 2050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, a[MAXN], b[MAXN];
double k[MAXN];
void solve()
{
    ll v, e, h;
    cin >> n >> m >> h >> e;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    vector<vector<double>> dis(h + 10, vector<double>(h + 10, INF));
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }

    double ans = 1e18;
    ll u, w;
    for (int i = 1; i <= e; i++)
    {
        cin >> u >> v >> w;
        if (w < dis[u][v])
        {
            dis[u][v] = w;
            dis[v][u] = w;
        }
    }
    for (int i = 0; i <= h; i++)
    {
        dis[0][i] = 0;
        dis[i][i] = 0;
        dis[i][0] = 0;
    }
    for (int k = 1; k <= h; k++)
    {
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= h; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    vector<vector<array<double, 2>>> dp(n + 10, vector<array<double, 2>>(m + 10, {INF, INF}));
    for (int i = 0; i <= m; i++)
    {
        dp[0][i][0] = 0, dp[0][i][1] = 0;
    }
    // 到达i位，用了j次操作[0/1]用不用的最小期望
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m && j <= i; j++)
        {
            if (j >= 1)
            {
                dp[i][j][0] = min({dp[i][j][0], dp[i - 1][j][1] + dis[a[i - 1]][a[i]] * (1 - k[i - 1]) + dis[b[i - 1]][a[i]] * k[i - 1]});
                dp[i][j][1] = min({dp[i][j][1], dp[i - 1][j - 1][0] + dis[a[i - 1]][b[i]] * k[i] + dis[a[i - 1]][a[i]] * (1 - k[i]),
                                   dp[i - 1][j - 1][1] + dis[a[i - 1]][a[i]] * (1 - k[i - 1]) * (1 - k[i]) +
                                       dis[a[i - 1]][b[i]] * (1 - k[i - 1]) * k[i] +
                                       dis[b[i - 1]][a[i]] * k[i - 1] * (1 - k[i]) + dis[b[i - 1]][b[i]] * k[i - 1] * k[i]});
            }
            // 不操作
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dis[a[i - 1]][a[i]]);
        }
    }
    for (int i = 0; i <= m; i++)
    {
        ans = min({ans, dp[n][i][0], dp[n][i][1]});
    }
    ans *= 100;
    ans = round(ans);
    ans /= 100;
    cout << fixed << setprecision(2) << ans << '\n';
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