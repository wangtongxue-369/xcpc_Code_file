/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<vector<ll>> ve(n + 10);
    vector<ll> f(n + 10, 0);
    vector<array<ll, 2>> dp(n + 10);
    for (int i = 1; i <= n - 1; i++)
    {
        ll k, l;
        cin >> k >> l;
        ve[k].push_back(l);
        f[l]++;
    }
    ll root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 0)
        {
            root = i;
            break;
        }
    }
    function<void(ll x)> dfs = [&](ll x)
    {
        if (ve[x].size() == 0)
        {
            dp[x][1] = max(a[x], dp[x][1]);
            dp[x][0] = 0;
            return;
        }
        ll bx = 0;
        ll xu = 0;
        for (auto it : ve[x])
        {
            dfs(it);
            xu = max(xu, xu + dp[it][0]);
            bx = max({bx, bx + dp[it][1], bx + dp[it][0]});
        }
        dp[x][0] = bx;
        dp[x][1] = max(xu + a[x], xu);
    };
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << '\n';
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