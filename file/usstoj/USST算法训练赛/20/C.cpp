#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1000007;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    vector<vector<ll>> dp(110, vector<ll>(110, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    dp[0][0] = 1;
    // dp[i][j] 为考虑到第i种花，摆m盆的时候的答案
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= a[i]; k++)
            {
                if (j - k >= 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
            }
        }
    }
    cout << dp[n][m];

    vector<ll> d(m + 10, 0);
    d[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = 1; k <= a[i]; k++)
            {
                if (j - k >= 0)
                {
                    d[j] = (d[j] + d[j - k]) % mod;
                }
            }
        }
    }
    cout << d[m] << '\n';
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
// dp[i][j]