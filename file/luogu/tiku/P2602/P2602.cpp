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
ll ksm(ll a, ll b)
{
    ll s = 1;
    while (b)
    {
        if (b & 1)
            s *= a;
        b >>= 1;
        a *= a;
    }
    return s;
}
auto solve(ll x)
{
    ll num = 0;
    ll t = x;
    while (t)
    {
        // t /= 10;
        num++;
        a[num] = t % 10;
        t /= 10;
    }
    ll dp[15][12][12];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 9; i++)
    {
        dp[1][i][i] = 1;
    }

    // dp[i][j][k] 长度为i的数，最高位为j，数码k出现的次数
    for (int i = 2; i <= 12; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                for (int p = 0; p <= 9; p++)
                {
                    dp[i][j][p] += dp[i - 1][k][p];
                }
            }
            dp[i][j][j] += ksm(10, i - 1);
        }
    }
    vector<ll> an(20);
    // 位数少于num
    for (int i = num - 1; i >= 1; i--)
    {
        for (int j = 1; j <= 9; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                an[k] += dp[i][j][k];
            }
        }
    }
    // 最高位等于小于a【】
    for (int i = 1; i < a[num]; i++)
    {
        for (int k = 0; k <= 9; k++)
        {
            an[k] += dp[num][i][k];
        }
    }
    for (int i = num - 1; i >= 1; i--)
    {
        for (int j = 0; j < a[i]; j++)
        {
            for (int k = 0; k <= 9; k++)
            {
                an[k] += dp[i][j][k];
            }
        }
        for (int p = num; p > i; p--)
        {
            an[a[p]] += a[i] * ksm(10, i - 1);
        }
    }

    return an;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        ll l, r;
        cin >> l >> r;
        auto it1 = solve(r + 1);
        auto it2 = solve(l);
        for (int i = 0; i <= 9; i++)
        {
            cout << it1[i] - it2[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}