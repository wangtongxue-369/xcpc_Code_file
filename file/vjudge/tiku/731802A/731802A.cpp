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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll dp[10][30][(1ll << 15)];
void solve()
{
    ll kp;
    cin >> n >> kp;
    dp[0][0][0] = 1;
    vector<PII> ve; // 合法情况
    for (ll i = 0; i < (1ll << n); i++)
    {
        ll p = i, cnt = 0;
        while (p)
        {
            if (p % 2)
            {
                cnt++;
            }
            p >>= 1;
        }
        // cout << i << ' ' << (i << 1) << ' ' << (i >> 1) << '\n';
        if (((i << 1) & i) == 0 && ((i >> 1) & i) == 0)
        {
            ve.push_back({i, cnt});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < ve.size(); j++)
        {
            for (int k = 0; k < ve.size(); k++)
            {
                ll p1 = ve[j].first, p2 = ve[k].first;
                ll k1 = ve[j].second, k2 = ve[k].second;
                if (((p1 << 1) & p2) == 0 && (p1 & p2) == 0 && ((p1 >> 1) & p2) == 0)
                {
                    for (int l = 0; l <= kp; l++)
                    {
                        dp[i][k2 + l][p2] += dp[i - 1][l][p1];
                    }
                }
            }
        }
    }
    for (auto it : ve)
    {
        ans += dp[n][kp][it.first];
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