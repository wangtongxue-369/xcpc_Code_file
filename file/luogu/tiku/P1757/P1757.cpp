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
void solve()
{
    cin >> m >> n;
    ll zs = 0;
    map<ll, vector<PII>> ma;
    ll s1, s2, s3;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2 >> s3;
        ma[s3].push_back({s1, s2});
    }
    ll p = 1;
    vector<vector<ll>> dp(ma.size() + 10, vector<ll>(m + 10));
    for (auto &[c, ve] : ma)
    {
        for (ll i = m; i >= 0; i--)
        {
            dp[p][i] = dp[p - 1][i];
            for (auto &[w, v] : ve)
            {
                if (i - w >= 0)
                {
                    dp[p][i] = max(dp[p][i], dp[p - 1][i - w] + v);
                }
                ans = max(ans, dp[p][i]);
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