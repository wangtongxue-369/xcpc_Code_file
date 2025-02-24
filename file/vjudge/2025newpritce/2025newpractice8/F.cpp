#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 150;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN];
void solve()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            bool flag = 0;
            for (int k = 1; k <= n; k++)
            {
                for (int l = 1; l < m; l++)
                {
                    if ((a[k][l] == j && a[k][l + 1] == i) || (a[k][l] == i && a[k][l + 1] == j))
                    {
                        flag = 1;
                    }
                }
            }
            if (flag == 0)
            {
                ans++;
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
