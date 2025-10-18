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
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 下降子序列 长度<=2
    // a[i] a[j]
    //
    // vector<ll> dp(n+10);
    vector<vector<ll>> f(n + 10, vector<ll>(n + 10)), f2(n + 10, vector<ll>(n + 10));
    f[0][0] = 1;
    // 以i开头，j结尾的方案
    // i最大 j次大
    for (int k = 1; k <= n; k++)
    {
        ll x = a[k];
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                f2[i][j] = 0;
            }
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                f2[i][j] += f[i][j];
                f2[i][j] %= mod;
                if (a[k] >= i)
                {
                    f2[x][j] += f[i][j];
                    f2[x][j] %= mod;
                }
                else if (a[k] >= j)
                {
                    f2[i][x] += f[i][j];
                    f2[i][x] %= mod;
                }
            }
        }
        f = f2;
    }
    ans = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            ans += f[i][j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
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