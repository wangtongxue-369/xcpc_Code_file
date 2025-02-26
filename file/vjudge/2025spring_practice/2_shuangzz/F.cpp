#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1010;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (i == 1 && a[i][j] == 2)
            {
                f[j] = 1;
            }
        }
    }
    while (k--)
    {
        ll x = 1, y;
        cin >> y;
        if (f[y] != 0)
        {
            x = f[y];
            x++;
        }
        while (a[x][y] == 2)
        {
            f[y]++;
            x++;
        }
        while (x <= n)
        {
            if (a[x][y] == 1)
            {
                a[x][y] = 2;
                y++;
                continue;
            }
            if (a[x][y] == 2)
            {
                a[x][y] = 2;
                x++;
                continue;
            }
            if (a[x][y] == 3)
            {
                a[x][y] = 2;
                y--;
                continue;
            }
        }
        cout << y << ' ';
    }
    cout << '\n';
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
