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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN], c[MAXN];
void solve()
{
    cin >> n;
    vector<vector<ll>> dp(n + 10, vector<ll>(2, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][1] + a[i], dp[i - 1][0] + a[i] + c[i - 1] + c[i]);
        dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + b[i] + c[i - 1] + c[i]);
    }
    cout << max(dp[n][1], dp[n][0]) << '\n';
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
