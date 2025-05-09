#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN];
void solve()
{
    n = 5, m = 5;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ll maxn = a[i][j];
            ll minn = a[i][j];
            for (int k = 1; k <= m; k++)
            {
                maxn = max(maxn, a[i][k]);
            }
            for (int k = 1; k <= n; k++)
            {
                minn = min(minn, a[k][j]);
            }
            if (maxn == minn)
            {
                cout << i << ' ' << j << ' ' << a[i][j] << '\n';
                return;
            }
        }
    }
    cout << "not found" << '\n';
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
