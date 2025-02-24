#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 200;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN][MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i][j - 1] + a[i][j] + f[i - 1][j] - f[i - 1][j - 1];
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    ans = -1e18;
    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                for (int y2 = 1; y2 <= n; y2++)
                {
                    if (x2 < x1 || y2 < y1)
                    {
                        continue;
                    }
                    ans = max(ans, f[x2][y2] + f[x1 - 1][y1 - 1] - f[x2][y1 - 1] - f[x1 - 1][y2]);
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
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
