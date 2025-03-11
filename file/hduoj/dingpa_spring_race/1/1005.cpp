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
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void solve()
{
    cin >> n >> m;
    vector<vector<ll>> t(n + 2, vector<ll>(m + 2, 0));
    vector<vector<ll>> d(n + 2, vector<ll>(m + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> t[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> d[i][j];
        }
    }
    ans = 1e18;
    // 上 0 左1 下2 右 3
    vector<vector<vector<long long>>> dist(n + 5, vector<vector<long long>>(m + 5, vector<long long>(4, 1e18)));
    priority_queue<array<ll, 4>> q;
    q.push({-1 * t[1][1], 1, 1, 3});
    dist[1][1][3] = t[1][1];
    while (q.size())
    {
        auto [dis, x, y, dir] = q.top();
        q.pop();
        dis *= -1;
        if (dis > dist[x][y][dir])
        {
            continue;
        }
        // 区域内转向
        for (int i = 0; i < 4; i++)
        {
            if (i != dir && dist[x][y][i] > dis + d[x][y])
            {
                dist[x][y][i] = dis + d[x][y];
                q.push({-1 * dist[x][y][i], x, y, i});
            }
        }
        // 去其他区域 有可能转向
        for (int i = 0; i < 4; i++)
        {
            ll xx = x + tx[i];
            ll yy = y + ty[i];
            if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
            {
                ll di = dis + t[xx][yy] + (dir == i ? 0 : d[x][y]);
                if (dist[xx][yy][i] > di)
                {
                    dist[xx][yy][i] = di;
                    q.push({-1 * dist[xx][yy][i], xx, yy, i});
                }
            }
        }
    }

    cout << dist[n][m][2] << '\n';
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
