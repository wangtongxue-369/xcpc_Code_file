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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    k *= 2;
    string s;
    vector<vector<ll>> ve(n + 10);
    vector<vector<ll>> dp(k + 5, vector<ll>(n + 10));
    cin >> s;
    s = ' ' + s;
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
    }
    // k为奇数 最后一步是A走
    //    偶数 最后一步是B走
    char tu;
    if (k % 2 == 1)
    {
        tu = 'A';
    }
    else
    {
        tu = 'B';
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
        {
            dp[k + 1][i] = 1;
        }
        else
        {
            dp[k + 1][i] = 2;
        }
    }
    for (int w = k; w >= 1; w--)
    {
        // cout << w << ' ' << tu << '\n';
        for (int i = 1; i <= n; i++)
        {
            if (tu == 'A')
            {
                for (auto it : ve[i])
                {
                    if (dp[w + 1][it] == 1)
                    {
                        dp[w][i] = 1;
                        break;
                    }
                    else
                    {
                        dp[w][i] = 2;
                    }
                }
            }
            else
            {
                for (auto it : ve[i])
                {
                    // cout << i << ' ' << it << '\n';
                    if (dp[w + 1][it] == 2)
                    {
                        dp[w][i] = 2;
                        break;
                    }
                    else
                    {
                        dp[w][i] = 1;
                    }
                }
            }
        }
        // cout << "! " << w << '\n';
        //  for (int i = 1; i <= n; i++)
        //  {
        //      cout << dp[w][i] << ' ';
        //  }
        //  cout << '\n';
        if (w != 1)
        {
            tu = (tu == 'A' ? 'B' : 'A');
        }
    }
    // cout << "!!!" << tu << '\n';
    if (dp[1][1] == 1)
    {
        cout << "Alice\n";
    }
    else
    {
        cout << "Bob\n";
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