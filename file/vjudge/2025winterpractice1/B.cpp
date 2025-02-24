#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 510;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN][MAXN];
void solve()
{
    cin >> n >> m;
    ll p = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = p++;
        }
    }
    ll x, y, r, z;
    for (int w = 1; w <= m; w++)
    {
        cin >> x >> y >> r >> z;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                f[i][j] = a[i][j];
            }
        }
        if (z == 0)
        {
            for (int i = x - r; i <= x + r; i++)
            {
                ll p = 0;
                for (int j = y - r; j <= y + r; j++)
                {
                    a[x - y + j][x + y - i] = f[i][j];
                    // a[i][y + r - p++] = f[j][i];
                }
            }
        }
        else
        {
            for (int i = x - r; i <= x + r; i++)
            {
                for (int j = y - r; j <= y + r; j++)
                {
                    a[x + y - j][y - x + i] = f[i][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
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