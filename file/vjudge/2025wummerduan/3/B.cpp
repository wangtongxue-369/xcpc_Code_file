/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll dp[305][305][305][4];
void solve()
{
    ll q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<ll> d(n + 10);
    s = ' ' + s + ' ';
    ll sumw = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '?')
        {
            d[i] = d[i - 1] + 1;
        }
    }
    dp[0][0][0][3] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x <= sumw; x++)
        {
            for (int y = 0; y <= sumw; y++)
            {
                ll z = (d[i] - x - y);
                if (z < 0)
                {
                    break;
                }
                if (s[i] != '?')
                {

                    for (int j = 0; j < 4; j++)
                    {
                        if (s[i] - 'a' != j)
                        {
                            dp[i][x][y][s[i] - 'a'] = (dp[i - 1][x][y][s[i] - 'a'] + dp[i - 1][x][y][j]) % mod;
                        }
                    }
                    continue;
                }
                if (i == n || s[i + 1] != 'a' && x > 0)
                {
                    dp[i][x][y][0] = (dp[i - 1][x - 1][y][1] + dp[i - 1][x - 1][y][2] + dp[i - 1][x][y][3]) % mod;
                }
                if (i == n || s[i + 1] != 'b' && y > 0)
                {
                    dp[i][x][y][1] = (dp[i - 1][x][y - 1][0] + dp[i - 1][x][y - 1][2] + dp[i - 1][x][y - 1][3]) % mod;
                }
                if (i == n || s[i + 1] != 'c' && z > 0)
                {
                    dp[i][x][y][2] = (dp[i - 1][x][y][0] + dp[i - 1][x][y][1] + dp[i - 1][x][y][3]) % mod;
                }
            }
        }
    }
    while (q--)
    {
        // dp[i][x][y][z] 考虑到i时，使用x个a y个b 最后一个字母是z时的方案数
        for (int i = 1; i <= n; i++)
        {
            if (s[i] != '?')
            {
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}