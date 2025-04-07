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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN], f[200][400];
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    memset(f, -1, sizeof(f));
    f[0][1] = a[1];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // f[i][j];
            if (f[i - 1][j] != -1)
            {
                // cout << i << ' ' << j << '\n';
                f[i][j] = max(f[i][j], f[i - 1][j]);
                if (j + b[i] <= n)
                {
                    f[i][j + b[i]] = max(f[i][j + b[i]], f[i - 1][j] + a[j + b[i]]);
                }
            }
        }
    }
    cout << f[m][n] << '\n';
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
