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
ll _ = 1, n, m, ans = 0, a[510][510], f[510][510];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= 500; i++)
    {
        for (int j = 1; j <= 500; j++)
        {
            a[i][j] = 0;
            f[i][j] = 1e18;
        }
        f[i][1] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        ll r, x;
        cin >> r;
        for (int j = 1; j <= r; j++)
        {
            cin >> x;
            a[i][x] = 1;
        }
    }
    queue<PII> q;
    for (int i = 1; i <= n; ++i)
    {
        if (!a[i][1])
        {
            f[i][1] = 1;
            q.emplace(i, 1);
        }
    }

    ans = -1;
    int dirs[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        if (j == m)
        {
            ans = f[i][j];
            break;
        }

        for (const auto &[di, dj] : dirs)
        {
            int ni = i + di;
            int nj = j + dj;

            if (ni >= 1 && ni <= n && nj >= 1 && nj <= m && !a[ni][nj])
            {
                if (f[ni][nj] > f[i][j] + 1)
                {
                    f[ni][nj] = f[i][j] + 1;
                    q.emplace(ni, nj);
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
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}