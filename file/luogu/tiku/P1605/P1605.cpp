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
ll a[100][100];
ll vis[100][100];
ll sx, sy, fx, fy;
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void dfs(ll x, ll y)
{
    if (x == fx && y == fy)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        ll xx = x + tx[i];
        ll yy = y + ty[i];
        if (1 <= xx && xx <= n && 1 <= yy && yy <= m && vis[xx][yy] == 0 && a[xx][yy] == 0)
        {
            vis[xx][yy] = 1;
            dfs(xx, yy);
            vis[xx][yy] = 0;
        }
    }
}
void solve()
{
    ll k;
    cin >> n >> m >> k;
    cin >> sx >> sy >> fx >> fy;
    ll x, y;
    while (k--)
    {
        cin >> x >> y;
        a[x][y] = 1;
    }
    vis[sx][sy] = 1;
    dfs(sx, sy);
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