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
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    vector<ll> dp(n + 10, 0);
    for (int i = 1; i <= m; i++)
    {
        dp[i] = 1e18;
        for (int j = i; j >= max(0, i - 30); j--)
        {
            dp[i] = min(dp[i], dp[j] + (j - i) * (j - i) * (j - i) * (j - i));
        }
        dp[i] += a[i];
    }
    cout << dp[m] << '\n';
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
