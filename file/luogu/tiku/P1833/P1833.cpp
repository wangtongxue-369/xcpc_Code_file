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
    ll h1, m1, h2, m2, s1, s2;
    scanf("%lld:%lld", &h1, &m1);
    scanf("%lld:%lld", &h2, &m2);
    s1 = h1 * 60 + m1;
    s2 = h2 * 60 + m2;
    m = s2 - s1;
    cin >> n;
    vector<PII> ve;
    ll t, c, p;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> c >> p;
        if (p == 0)
        {
            p = 1000;
        }
        for (ll j = 1; j <= p; j <<= 1)
        {
            ve.push_back({j * t, j * c});
            p -= j;
        }
        if (p)
        {
            ve.push_back({t * p, c * p});
        }
    }
    vector<ll> dp(m + 10);
    for (auto [w, v] : ve)
    {
        for (int i = m; i >= w; i--)
        {
            dp[i] = max(dp[i], dp[i - w] + v);
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}