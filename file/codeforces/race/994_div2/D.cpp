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
ll _ = 1, n, m, ans = 0, a[300][300], f[300][300];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i <= n + 10; i++)
    {
        for (int j = 0; j <= m + 10; j++)
        {
            f[i][j] = 1e18;
        }
    }
    for (int i = 0; i < n; i++)
    {
        vector<ll> b(m + 10);
        for (int w = 0; w < m; w++)
        {
            for (int j = 0; j < m; j++)
            {
                b[j] = a[i][(j + w) % m];
            }
            vector<ll> g(m + 10, 1e18);
            for (int j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    g[j] = min(g[j], b[j]);
                }
                if (i >= 1)
                {
                    g[j] = min(g[j], f[i - 1][j] + b[j]);
                }
                if (j >= 1)
                {
                    g[j] = min(g[j], g[j - 1] + b[j]);
                }
                f[i][j] = min(f[i][j], g[j] + w * k);
            }
        }
    }
    cout << f[n - 1][m - 1] << '\n';
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
