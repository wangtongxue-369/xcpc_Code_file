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
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
char c[1010][1010];

ll ksm(ll x, ll y)
{
    x %= mod;
    if (y == 0)
        return 1;
    if (y & 1)
        return ksm(x * x, y >> 1) * x % mod;
    return ksm(x * x, y >> 1) % mod;
}
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void solve()
{
    ll sumd = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
            if (c[i][j] == '.')
            {
                sumd++;
            }
        }
    }
    vector<vector<ll>> vis(n + 10, vector<ll>(m + 10));
    ll p = 1;
    function<void(ll x, ll y)> dfs = [&](ll x, ll y)
    {
        for (int i = 0; i < 4; i++)
        {
            ll xx = x + dx[i];
            ll yy = y + dy[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && c[xx][yy] == '#' && vis[xx][yy] == 0)
            {
                vis[xx][yy] = p;
                dfs(xx, yy);
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '#' && vis[i][j] == 0)
            {
                vis[i][j] = p;
                dfs(i, j);
                p++;
            }
        }
    }
    p--;
    ll fm = 1 * ksm(sumd, mod - 2) % mod;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (c[i][j] == '#')
            {
                continue;
            }
            set<ll> se;
            for (int k = 0; k < 4; k++)
            {
                ll xx = i + dx[k];
                ll yy = j + dy[k];
                if (1 <= xx && xx <= n && 1 <= yy && yy <= m && c[xx][yy] == '#')
                {
                    se.insert(vis[xx][yy]);
                }
            }
            ll s;
            if (se.size() == 0)
            {
                s = p + 1;
            }
            else if (se.size() == 1)
            {
                s = p;
            }
            else
            {
                s = p - se.size() + 1;
            }
            ans += (fm * s % mod);
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