#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
char a[1010][1010];
string s = "A1543";
void solve()
{
    ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    ll t = 1, i, j, pos = 0;
    while (t <= min(n, m) / 2)
    {
        pos = 0;
        set<pair<ll, ll>> se;
        ll sdsd = 2;
        while (sdsd--)
        {
            i = t;
            for (j = t + 1; j <= m - t + 1; j++)
            {
                if (a[i][j] == s[pos + 1])
                {
                    pos++;
                    if (pos == 4)
                    {
                        pos = 0;
                        se.insert({i, j});
                    }
                    continue;
                }
                else
                {
                    if (a[i][j] == s[1])
                    {
                        pos = 1;
                    }
                    else
                    {
                        pos = 0;
                    }
                }
            }
            j = m - t + 1;
            for (i = t + 1; i <= n - t + 1; i++)
            {
                // cout << i << ' ' << j << ' ' << pos << ' ' << a[i][j] << '\n';
                if (a[i][j] == s[pos + 1])
                {
                    pos++;
                    if (pos == 4)
                    {
                        // cout << '!' << '\n';
                        pos = 0;
                        se.insert({i, j});
                    }
                    continue;
                }
                else
                {
                    if (a[i][j] == s[1])
                    {
                        pos = 1;
                    }
                    else
                    {
                        pos = 0;
                    }
                }
            }
            i = n - t + 1;
            for (j = m - t + 1 - 1; j >= t; j--)
            {
                if (a[i][j] == s[pos + 1])
                {
                    pos++;
                    if (pos == 4)
                    {
                        pos = 0;
                        se.insert({i, j});
                    }
                    continue;
                }
                else
                {
                    if (a[i][j] == s[1])
                    {
                        pos = 1;
                    }
                    else
                    {
                        pos = 0;
                    }
                }
            }
            j = t;
            for (i = n - t + 1 - 1; i >= t; i--)
            {
                if (a[i][j] == s[pos + 1])
                {
                    pos++;
                    if (pos == 4)
                    {
                        pos = 0;
                        se.insert({i, j});
                    }
                    continue;
                }
                else
                {
                    if (a[i][j] == s[1])
                    {
                        pos = 1;
                    }
                    else
                    {
                        pos = 0;
                    }
                }
            }
        }
        ans += se.size();
        t++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
