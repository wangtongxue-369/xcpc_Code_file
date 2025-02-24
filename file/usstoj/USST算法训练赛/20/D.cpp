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
ll _ = 1, n, m, ans = 0, a[11][11], vis[11][11];

ll tx[] = {1, 2, 2, 1, -1, -2, -2, -1};
ll ty[] = {2, 1, -1, -2, -2, -1, 1, 2};

void dfs(ll x, ll y, ll t)
{
    if (t == n * m)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        ll xx = tx[i] + x;
        ll yy = ty[i] + y;
        if (1 <= xx && xx <= n && 1 <= yy && yy <= m && vis[xx][yy] == 0)
        {
            vis[xx][yy] = 1;
            dfs(xx, yy, t + 1);
            vis[xx][yy] = 0;
        }
    }
}
void solve()
{
    ans = 0;
    ll x, y;
    cin >> n >> m >> x >> y;
    memset(vis, 0, sizeof(vis));
    x++, y++;
    vis[x][y] = 1;
    dfs(x, y, 1);
    cout << ans << '\n';
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
