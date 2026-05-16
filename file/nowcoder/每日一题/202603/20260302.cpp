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
const ll mod = 1e4 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
vector<vector<ll>> ve(100);
int vis[10];
void dfs(int a)
{
    vis[a] = 1;
    for (auto it = ve[a].begin(); it != ve[a].end(); ++it)
    {
        int b = *it;
        if (!vis[b])
        {
            vis[b] = 1;
            dfs(b);
        }
    }
}
void solve()
{
    ll s;
    cin >> s;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        ve[a].push_back(b);
    }
    ans = 1;
    while (s)
    {
        int a = s % 10;
        s /= 10;
        memset(vis, 0, sizeof(vis));
        dfs(a);
        int cnt = 0;
        for (int i = 0; i < 10; ++i)
        {
            cnt += vis[i];
        }
        ans *= cnt;
    }
    ans %= mod;
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