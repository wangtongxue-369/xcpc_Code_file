#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1010;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
char a[MAXN][MAXN];
ll f[MAXN][MAXN];
ll tx[] = {0, -1, 0, 1, 0};
ll ty[] = {0, 0, -1, 0, 1};
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
            if (a[i][j] == '#')
            {
                for (int k = 0; k < 5; k++)
                {
                    f[i + tx[k]][j + ty[k]] = 1;
                }
            }
        }
    }
    vector<vector<int>> vis(n + 10, vector<int>(m + 10, -1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '.' && vis[i][j] == -1)
            {

                vis[i][j] = i * m + j;
                set<PII> se;
                queue<PII> q;
                q.emplace(i, j);
                se.insert({i, j});
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    se.insert({x, y});
                    if (f[x][y] == 1)
                    {
                        continue;
                    }
                    for (int k = 1; k <= 4; k++)
                    {
                        ll xx = x + tx[k];
                        ll yy = y + ty[k];
                        if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == '.' && vis[xx][yy] != vis[x][y])
                        {
                            vis[xx][yy] = vis[x][y];
                            q.emplace(xx, yy);
                        }
                    }
                }
                ans = max(ans, (ll)se.size());
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
