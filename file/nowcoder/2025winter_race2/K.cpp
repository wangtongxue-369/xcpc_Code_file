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
ll _ = 1, n, m, ans = 0;
char a[550][550];
ll s[550][550];
bool vis[550][550];
ll tx[] = {-1, 0, 1, 0};
ll ty[] = {0, -1, 0, 1};
void dfs(ll x, ll y, ll p)
{
    for (int i = 0; i < 4; i++)
    {
        ll xx = x + tx[i];
        ll yy = y + ty[i];
        if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
        {
            if (vis[xx][yy] == 0 && a[xx][yy] == '1')
            {
                vis[xx][yy] = 1;
                s[xx][yy] = p;
                dfs(xx, yy, p);
            }
        }
    }
}
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
    ll p = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '1' && vis[i][j] == 0)
            {
                vis[i][j] = 1;
                s[i][j] = p;
                dfs(i, j, p);
                p++;
            }
        }
    }
    p--;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << s[i][j];
    //     }
    //     cout << '\n';
    // }
    vector<set<PII>> ve(p + 10);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == '0')
            {
                for (int x = 0; x < 4; x++)
                {
                    ll xx = i + tx[x];
                    ll yy = j + ty[x];
                    if (1 <= xx && xx <= n && 1 <= yy && yy <= m)
                    {
                        if (a[xx][yy] == '1')
                        {
                            ve[s[xx][yy]].insert({i, j});
                        }
                    }
                }
            }
        }
    }
    ans = 1e18;
    for (int i = 1; i <= p; i++)
    {
        ans = min(ans, (ll)ve[i].size());
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
