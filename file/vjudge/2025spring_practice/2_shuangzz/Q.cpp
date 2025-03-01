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
ll _ = 1, n, m, ans = 0;
char a[110][110];
ll f[110][110];
ll tx[] = {0, -1, 0, 1, 0, -1, -1, 1, 1};
ll ty[] = {0, 0, -1, 0, 1, -1, 1, -1, 1};
void dfs(ll x, ll y)
{
    for (int i = 1; i <= 8; i++)
    {
        ll xx = x + tx[i];
        ll yy = y + ty[i];
        if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == 'W' && f[xx][yy] == 0)
        {
            f[xx][yy] = 1;
            dfs(xx, yy);
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j] == 0 && a[i][j] == 'W')
            {
                ans++;
                f[i][j] = 1;
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
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
