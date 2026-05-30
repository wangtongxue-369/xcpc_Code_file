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
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, f[MAXN];

ll dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
ll dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void solve()
{
    cin >> n >> m;
    vector<vector<char>> a(n + 10, vector<char>(m + 10));
    vector<vector<ll>> vis(n + 10, vector<ll>(m + 10, -1));
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
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '#')
            {
                continue;
            }
            bool flag = false;
            for (int k = 0; k < 8; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x < 1 || x > n || y < 1 || y > m)
                {
                    continue;
                }

                if (a[x][y] == '#')
                {
                    flag = true;
                }
            }
            if (flag)
            {
                vis[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 8; k++)
        {
            ll nx = x + dx[k];
            ll ny = y + dy[k];
            if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] != -1)
            {
                continue;
            }
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vis[i][j] != -1 && vis[i][j] % 2 == 1)
            {
                cout << '#';
            }
            else
            {
                cout << '.';
            }
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