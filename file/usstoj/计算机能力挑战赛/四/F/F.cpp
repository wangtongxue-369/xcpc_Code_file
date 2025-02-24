#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N]; // f[N];
bool f[101][101];
void dfs(ll x, ll y)
{
    if (f[x][y])
    {
        return;
    }
    if (x < 1 || y < 1 || x > n || y > m)
    {
        return;
    }
    f[x][y] = 1;
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x - 1, y);
}
void solve()
{
    ll cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char c;
            cin >> c;
            if (c == '0')
            {
                f[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (f[i][j] == 0)
            {

                cnt++;
                dfs(i, j);
            }
        }
    }

    cout << cnt;
    return;
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
