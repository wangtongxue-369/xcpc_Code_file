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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    n = a.length(), m = b.length();
    vector<vector<ll>> dp(n + 10, vector<ll>(m + 10, INF));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            ll pc = i + j - 1;
            if (i != 0)
            {
                if (a[i - 1] != c[pc])
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                }
            }
            if (j != 0)
            {
                if (b[j - 1] != c[pc])
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
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
