#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, v[N], t[N];
ll dp[10000010];
void solve()
{
    ll T;
    cin >> T >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= T; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i - t[j] >= 0)
            {
                dp[i] = max(dp[i - t[j]] + v[j], dp[i]);
            }
        }
    }
    cout << dp[T] << '\n';
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
