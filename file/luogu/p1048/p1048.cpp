#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 550;
ll _ = 1, n, m, ans = 0, t[N], v[N], dp[110][1100];
void solve()
{
    ll T, n;
    cin >> T >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = T; j >= 1; j--)
        {
            if (j - t[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j - t[i]] + v[i], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[n][T];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
