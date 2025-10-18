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
const ll mod = 1e8;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll cnt[(1ll << 13)];
ll dp[20][600][(1ll << 13)];
void solve()
{
    cin >> n >> m;
    vector<vector<ll>> a(n + 10, vector<ll>(m + 10));
    vector<ll> ve(n + 10);
    ll sum = 0;
    for (int i = 0; i < (1ll << m); i++)
    {
        ll p = i;
        while (p)
        {
            if (p % 2)
            {
                cnt[i]++;
            }
            p >>= 1;
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ll p = 0;
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                sum++;
                p += (1ll << (j - 1));
            }
        }
        ve[i] = p;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < (1ll << m); j++)
        {
            for (int k = 0; k < (1ll << m); k++)
            {
                if ((j & k) == 0 && (j & ve[i - 1]) == j && (k & ve[i]) == k && ((j << 1) & j) == 0 && ((j >> 1) & j) == 0 && ((k << 1) & k) == 0 && ((k >> 1) & k) == 0)
                {
                    for (int l = 0; l <= sum; l++)
                    {
                        dp[i][l + cnt[k]][k] += dp[i - 1][l][j];
                        dp[i][l + cnt[k]][k] %= mod;
                    }
                }
            }
        }
    }
    for (int j = 0; j <= sum; j++)
    {
        for (int k = 0; k < (1ll << m); k++)
        {
            ans += dp[n][j][k];
            ans %= mod;
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