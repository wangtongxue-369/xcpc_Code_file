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
ll _ = 1, n, m, k, ans = 0; // a[MAXN], f[MAXN];
char a[100][100];
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
bool f[100][100];
void dfs(ll x, ll y, ll s)
{
    if (s == k)
    {
        ans++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        ll xx = x + tx[i];
        ll yy = y + ty[i];
        if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] == '.' && f[xx][yy] == 0)
        {
            f[xx][yy] = 1;
            dfs(xx, yy, s + 1);
            f[xx][yy] = 0;
        }
    }
}
void solve()
{
    cin >> n >> m >> k;
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
            if (a[i][j] == '.')
            {
                f[i][j] = 1;
                dfs(i, j, 0);
                f[i][j] = 0;
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
