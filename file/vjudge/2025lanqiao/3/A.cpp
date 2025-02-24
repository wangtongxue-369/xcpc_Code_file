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
void solve()
{
    char c[55][55];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c[i][j];
        }
    }
    ans = 1e18;
    for (int x1 = 2; x1 < n; x1++)
    {
        for (int x2 = x1; x2 < n; x2++)
        {
            ll sum = 0;
            for (int i = 1; i < x1; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (c[i][j] != 'W')
                    {
                        sum++;
                    }
                }
            }
            for (int i = x1; i <= x2; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (c[i][j] != 'B')
                    {
                        sum++;
                    }
                }
            }
            for (int i = x2 + 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (c[i][j] != 'R')
                    {
                        sum++;
                    }
                }
            }
            ans = min(ans, sum);
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
