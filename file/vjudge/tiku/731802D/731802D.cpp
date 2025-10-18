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
ll dp[(1ll << 20)][21];
// 路径状态为i 当前在j点上的翻案书

int lowbit(int x)
{
    return x & -x;
}
void solve()
{
    cin >> n >> m;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i <= m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        dp[(1ll << i)][i] = 1;
    }

    for (int i = 0; i < (1ll << n); i++)
    {
        ll t = lowbit(i);
        // cout << t << '\n';
        for (int j = 0; j < n; j++)
        {
            if ((1ll << j) < t)
            {
                continue;
            }
            if (((1ll << j) & i) == 0)
            {
                continue;
            }
            for (auto it : ve[j])
            {
                if ((1ll << it) < t)
                {
                    continue;
                }
                if ((1ll << it) == t)
                {
                    ans += dp[i][j];
                }
                if ((1ll << it) > t && ((1ll << it) & i) == 0)
                {
                    dp[i | (1ll << it)][it] += dp[i][j];
                }
            }
        }
    }
    ans -= m;
    ans /= 2;
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