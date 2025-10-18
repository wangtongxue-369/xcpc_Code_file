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
ll _ = 1, n, m, ans = 0, a[MAXN], f[100][100];
ll dp[20][1ll << 20];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i][1ll << i] = a[i];
    }
    ll u, v, w;

    for (int i = 1; i <= k; i++)
    {
        cin >> u >> v >> w;
        u--, v--;
        f[u][v] = w;
    }
    // dp[20][(1ll<<20)];
    for (int i = 0; i < (1ll << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (((1ll << j) & i) != 0)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if ((i & (1ll << k)))
                {
                    dp[j][i | (1ll << j)] = max(dp[j][i | (1ll << j)], dp[k][i] + a[j] + f[k][j]);
                }
            }
        }
    }
    ans = -1e18;
    for (int i = 0; i < (1ll << n); i++)
    {
        ll p = i;
        ll cnt = 0;
        while (p)
        {
            if (p & 1)
            {
                cnt++;
            }
            p >>= 1;
        }
        if (cnt == m)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dp[j][i]);
            }
        }
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