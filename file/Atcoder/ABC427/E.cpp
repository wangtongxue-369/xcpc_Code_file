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
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void solve()
{
    cin >> n >> m;
    vector<vector<char>> a(2 * n + 10, vector<char>(2 * m + 10));
    vector<vector<ll>> c(n + 10, vector<ll>(m + 10));
    ll px = 0, py = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == '#')
            {
                c[i][j] = 1;
            }
            if (a[i][j] == 'T')
            {
                px = i, py = j;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            c[i][j] += c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1];
        }
    }
    // 操作数
    set<array<ll, 6>> se;
    priority_queue<array<ll, 7>, vector<array<ll, 7>>, greater<array<ll, 7>>> q;
    q.push({0, 1, 1, n, m, n + 1, m + 1});
    se.insert({1, 1, n, m, n + 1, m + 1});
    while (!q.empty())
    {
        auto [cc, ax, ay, bx, by, dx, dy] = q.top();
        q.pop();
        if (c[bx][by] - c[ax - 1][by] - c[bx][ay - 1] + c[ax - 1][ay - 1] == 0)
        {
            cout << cc << '\n';
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            ll nax = ax, nay = ay, nbx = bx, nby = by;
            ll xx = dx + tx[i];
            ll yy = dy + ty[i];
            nax = max(nax, xx - n), nay = max(nay, yy - m), nbx = min(nbx, xx - 1), nby = min(nby, yy - 1);
            if (xx > 2 * n + 1 || xx < 1 || yy > 2 * m + 1 || yy < 1)
            {
                continue;
            }
            ll X = px + xx - n - 1, Y = py + yy - m - 1;
            if (!(nax <= X && X <= nbx && nay <= Y && Y <= nby && a[X][Y] == '#'))
            {
                if (se.count({nax, nay, nbx, nby, xx, yy}))
                {
                    continue;
                }
                se.insert({nax, nay, nbx, nby, xx, yy});
                q.push({cc + 1, nax, nay, nbx, nby, xx, yy});
            }
        }
    }
    cout << -1 << '\n';
    return;
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