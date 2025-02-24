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
    ll x, y, z;
    cin >> x >> y >> z;
    vector<vector<ll>> dp(3e5 + 10, vector<ll>(2, -1));
    string s;
    cin >> s;
    n = s.length();
    s = ' ' + s;
    dp[0][0] = 0;
    dp[0][1] = z;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'a')
        {
            dp[i][0] = min({dp[i - 1][1] + min(z + x, y + z), dp[i - 1][0] + min(x, z + y + z)});
            dp[i][1] = min({dp[i - 1][1] + min(y, z + x + z), dp[i - 1][0] + min(x + z, y + z)});
        }
        else
        {
            // A
            dp[i][0] = min(dp[i - 1][0] + min(y, z + x + z), dp[i - 1][1] + min(x + z, y + z));
            dp[i][1] = min(dp[i - 1][1] + min(x, z + y + z), dp[i - 1][0] + min(y + z, z + x));
        }
    }
    cout << min(dp[n][0], dp[n][1]) << '\n';
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
