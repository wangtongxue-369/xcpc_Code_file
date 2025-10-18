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
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> dp(n + 10);
    for (int i = 1; i <= n; i++)
    {
        ve[a[i]].push_back(i);
        ll len = ve[a[i]].size();
        dp[i] = dp[i - 1];
        if (len >= a[i])
        {
            dp[i] = max(dp[i - 1], dp[ve[a[i]][len - a[i]] - 1] + a[i]);
        }
        // ve[a[i]].push_back(i);
    }
    cout << dp[n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
struct DSU
{
    std::vector<int> fa, sz;
    void init(int n)
    {
        fa.resize(n + 1);
        std::iota(fa.begin(), fa.end(), 0);
        sz.assign(n + 1, 1);
    }
    int leader(int x)
    {
        while (x != fa[x])
        {
            x = fa[x];
        }
        return x;
    }
    void join(int x, int y)
    {
        x = leader(x);
        y = leader(y);
        if (x != y)
        {
            if (sz[x] < sz[y])
            {
                std::swap(x, y);
            }
            sz[x] += sz[y];
            fa[y] = x;
        }
    }
};