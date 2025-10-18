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
ll _ = 1, n, ans = 0, k;
void solve()
{
    cin >> n >> k;
    vector<PII> ve;
    ll v, w, m;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w >> m;
        for (ll j = 1; j <= m; j <<= 1)
        {
            ve.push_back({j * v, j * w});
            m -= j;
        }
        if (m)
        {
            ve.push_back({v * m, w * m});
        }
    }
    vector<ll> dp(k + 10, 0);
    for (auto [v, w] : ve)
    {
        for (int i = k; i >= w; i--)
        {
            dp[i] = max(dp[i], dp[i - w] + v);
        }
    }
    cout << dp[k] << '\n';
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