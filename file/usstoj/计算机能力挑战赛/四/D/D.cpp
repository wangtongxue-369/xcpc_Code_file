#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 110;
ll _ = 1, n, m, ans = 0, a[N][N], f[N][N];
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
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i - 1 >= 0)
            {
                f[i][j] = max(f[i][j], f[i - 1][j] + a[i][j]);
            }
            if (j - 1 >= 0)
            {
                f[i][j] = max(f[i][j], f[i][j - 1] + a[i][j]);
            }
        }
    }
    cout << f[n][m] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
