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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
char a[110][110];
bool f[110][110];
bool flag = 0;
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void dfs(ll x, ll y)
{
    if (x == n && y == n)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        ll xx = tx[i] + x;
        ll yy = ty[i] + y;
        if (1 <= xx && xx <= n && 1 <= yy && yy <= n && f[xx][yy] == 0 && (a[xx][yy] == '.' || a[xx][yy] == 't'))
        {
            f[xx][yy] = 1;
            dfs(xx, yy);
            f[xx][yy] = 0;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[0][i] = '.';
        a[n + 1][i] = '.';
        a[i][0] = '.';
        a[i][n + 1] = '.';
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(f, 0, sizeof(f));
    flag = 0;
    dfs(1, 1);
    if (flag == 0)
    {
        cout << 0 << '\n';
        return;
    }
    flag = 0;
    ans = 2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'x' || a[i][j] == 's' || a[i][j] == 't')
            {
                continue;
            }
            memset(f, 0, sizeof(f));
            flag = 0;
            a[i][j] = 'x';
            f[1][1] = 1;
            dfs(1, 1);
            if (flag == 0)
            {
                cout << 1 << '\n';
                return;
            }
            a[i][j] = '.';
            f[1][1] = 0;
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
