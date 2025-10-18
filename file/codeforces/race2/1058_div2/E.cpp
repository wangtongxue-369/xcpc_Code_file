/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
ll _ = 1, n, m; // ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;

    vector<vector<char>> a(n + 2, vector<char>(m + 2));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    bool issw = 0;
    if (n > m)
    {
        issw = 1;
        swap(n, m);
        vector<vector<char>> aa(n + 2, vector<char>(m + 2));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                aa[i][j] = a[j][i];
            }
        }
        a = aa;
        aa.clear();
    }
    vector<vector<ll>> ans(n + 2, vector<ll>(m + 2, INF));
    vector<vector<ll>> cal(n + 2, vector<ll>(n + 2));
    vector<vector<ll>> ls(n + 2, vector<ll>(n + 2, 0));
    vector<vector<ll>> rs(n + 2, vector<ll>(n + 2, 0));
    for (int j = 1; j <= m; j++)
    {
        for (int x1 = 1; x1 <= n; x1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                cal[x1][x2] = INF;
            }
        }
        for (int x1 = 1; x1 <= n; x1++)
        {
            for (int x2 = x1 + 1; x2 <= n; x2++)
            {
                if (ls[x1][x2] <= j && j <= rs[x1][x2])
                {
                    ll len1 = rs[x1][x2] - ls[x1][x2] + 1;
                    ll len2 = x2 - x1 + 1;
                    cal[x1][x2] = min(cal[x1][x2], len2 * len1);
                }
                if (a[x1][j] == '1' && a[x2][j] == '1')
                {
                    if (rs[x1][x2] == 0)
                    {
                        ls[x1][x2] = j;
                    }
                    else
                    {
                        ls[x1][x2] = rs[x1][x2];
                    }
                    ll p = ls[x1][x2] + 1;
                    while (p <= m && (!(a[x1][p] == '1' && a[x2][p] == '1')))
                    {
                        p++;
                    }
                    if (p <= m)
                    {
                        rs[x1][x2] = p;
                    }
                    else
                    {
                        rs[x1][x2] = 0;
                    }
                }
                if (ls[x1][x2] <= j && j <= rs[x1][x2])
                {
                    ll len1 = rs[x1][x2] - ls[x1][x2] + 1;
                    ll len2 = x2 - x1 + 1;
                    cal[x1][x2] = min(cal[x1][x2], len2 * len1);
                }
            }
        }
        for (int len = n; len >= 2; len--)
        {
            for (int i = 1; i + len - 1 <= n; i++)
            {
                cal[i][i + len - 1 - 1] = min({cal[i][i + len - 1 - 1], cal[i][i + len - 1]});
                cal[i + 1][i + len - 1] = min({cal[i + 1][i + len - 1], cal[i][i + len - 1]});
            }
        }
        for (int i = 1; i <= n; i++)
        {
            ans[i][j] = cal[i][i];
        }
    }
    if (issw)
    {
        swap(n, m);
        vector<vector<ll>> aa(n + 2, vector<ll>(m + 2));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                aa[i][j] = ans[j][i];
            }
        }
        ans = aa;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ans[i][j] == INF)
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << ans[i][j] << ' ';
            }
        }
        cout << '\n';
    }
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