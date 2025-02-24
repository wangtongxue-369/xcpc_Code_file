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
char a[1010][1010];
map<char, PII> ma;
bool vis[1010][1010];
void solve()
{
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    queue<PII> q;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][1] == 'L')
        {
            vis[i][1] = 1;
            q.emplace(i, 1);
        }
        if (a[i][m] == 'R')
        {
            vis[i][m] = 1;
            q.emplace(i, m);
        }
    }
    for (int j = 1; j <= m; j++)
    {
        if (a[1][j] == 'U')
        {
            vis[1][j] = 1;
            q.emplace(1, j);
        }
        if (a[n][j] == 'D')
        {
            vis[n][j] = 1;
            q.emplace(n, j);
        }
    }
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();
        ll ti, tj;
        if (1 <= i - 1 && i - 1 <= n && vis[i - 1][j] == 0 && a[i - 1][j] == 'D')
        {
            vis[i - 1][j] = 1;
            q.emplace(i - 1, j);
        }
        if (1 <= i + 1 && i + 1 <= n && vis[i + 1][j] == 0 && a[i + 1][j] == 'U')
        {
            vis[i + 1][j] = 1;
            q.emplace(i + 1, j);
        }
        if (1 <= j - 1 && j - 1 <= m && vis[i][j - 1] == 0 && a[i][j - 1] == 'R')
        {
            vis[i][j - 1] = 1;
            q.emplace(i, j - 1);
        }
        if (1 <= j + 1 && j + 1 <= m && vis[i][j + 1] == 0 && a[i][j + 1] == 'L')
        {
            vis[i][j + 1] = 1;
            q.emplace(i, j + 1);
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] == 0 && a[i][j] != '?')
            {
                ans++;
                continue;
            }
            if (vis[i][j] == 0)
            {
                if (1 <= i - 1 && i - 1 <= n)
                {
                    if (vis[i - 1][j] == 0)
                    {
                        ans++;
                        continue;
                    }
                }
                if (1 <= j - 1 && j - 1 <= m)
                {
                    if (vis[i][j - 1] == 0)
                    {
                        ans++;
                        continue;
                    }
                }
                if (1 <= i + 1 && i + 1 <= n)
                {
                    if (vis[i + 1][j] == 0)
                    {
                        ans++;
                        continue;
                    }
                }
                if (1 <= j + 1 && j + 1 <= m)
                {
                    if (vis[i][j + 1] == 0)
                    {
                        ans++;
                        continue;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ma['U'] = make_pair(-1, 0);
    ma['D'] = make_pair(1, 0);
    ma['L'] = make_pair(0, -1);
    ma['R'] = make_pair(0, 1);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
