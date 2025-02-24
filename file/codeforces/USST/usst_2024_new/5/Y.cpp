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
    cin >> n >> k;
    map<ll, ll> ma1, ma0;
    vector<vector<ll>> dp(n + 10, vector<ll>(70, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][a[i]] = 1;
        for (int j = 0; j <= 63; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j & a[i]] = (dp[i][j & a[i]] + dp[i - 1][j]) % mod;
        }
    }
    ans = 0;
    for (int i = 0; i < 64; i++)
    {
        if (__builtin_popcount(i) == k)
        {
            ans = (ans + dp[n][i]) % mod;
        }
    }
    cout << ans << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cin >> a[i];
    //     if (a[i] & (1 << k) == (1 << k))
    //     {
    //         // ma1[k]++;
    //         for (int j = k+1; j <= 6; j++)
    //         {
    //             if (j == k)
    //             {
    //                 continue;
    //             }
    //             else
    //             {
    //                 if (a[i] & (1 << j) == (1 << j))
    //                 {
    //                     ma1[j]++;
    //                 }
    //                 else
    //                 {
    //                     ma0[j]++;
    //                 }
    //             }
    //         }
    //     }
    // }
    // // 首先肯定时从k位为1的里面选，
    // // 并且每次里面必须带一个大于k的里面的0
    // // ans = (1 << (ma[k])) - 1;
    // bool flag = 1;
    // for (int i = k + 1; i <= 6; i++)
    // {
    //     if (ma1[i] == 0 && ma0[i] == 0)
    //     {
    //         continue;
    //     }
    //     if (ma1[i] > 0 && ma0[i] == 0)
    //     {
    //         cout << 0 << '\n';
    //         return;
    //     }
    // }
    // cout << ans << '\n';
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
