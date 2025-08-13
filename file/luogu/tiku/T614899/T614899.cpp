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
ll tx[] = {-1, -2, 1, 2, -2, -1, 1, 2};
ll ty[] = {-2, -1, -2, -1, 1, 2, 2, 1};
void solve()
{
    ll x1, y1;
    cin >> n >> m >> x1 >> y1;
    vector<vector<ll>> a(n + 10, vector<ll>(m + 10, 0));
    vector<vector<ll>> vis(n + 10, vector<ll>(m + 10, 0));
    function<void(ll x, ll y)> dfs = [&](ll x, ll y)
    {
        for (int i = 0; i < 8; i++)
        {
            ll xx = x + tx[i];
            ll yy = y + ty[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m && vis[xx][yy] == 0)
            {
                vis[xx][yy] = 1;
                dfs(xx, yy);
            }
        }
    };
    vis[x1][y1] = 1;
    dfs(x1, y1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << vis[i][j];
        }
        cout << '\n';
    }
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