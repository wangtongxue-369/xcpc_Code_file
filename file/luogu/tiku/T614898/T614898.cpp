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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll tx[] = {
    -1,
    0,
    1,
    0,
};
ll ty[] = {0, -1, 0, 1};
void solve()
{
    cin >> n >> m;
    vector<vector<char>> a(n + 10, vector<char>(m + 10));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> vis(n + 10, vector<ll>(m + 10));
    function<void(ll x, ll y)> dfs = [&](ll x, ll y)
    {
        for (int i = 0; i < 4; i++)
        {
            ll xx = x + tx[i];
            ll yy = y + ty[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && vis[xx][yy] == 0 && a[xx][yy] == '*')
            {
                vis[xx][yy] = 1;
                dfs(xx, yy);
            }
        }
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0 && a[i][j] == '*')
            {
                ans++;
                dfs(i, j);
            }
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