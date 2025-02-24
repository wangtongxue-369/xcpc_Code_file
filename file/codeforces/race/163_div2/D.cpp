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
    string s;
    cin >> s;
    s = ' ' + s;
    n = s.length() - 1;
    ans = 0;
    for (int len = n / 2; len >= 1; len--)
    {
        vector<ll> dp(n + 10, 0);
        for (int i = 1; i + len <= n; i++)
        {
            if (s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?')
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        for (int i = 0; i + len <= n; i++)
        {
            if (dp[i + len] - dp[i] == len)
            {
                cout << len << '\n';
                ans = max(ans, (ll)len);
            }
        }
    }
    cout << ans * 2 << '\n';
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
// 3*7+5
//((9 9) 2 2 3 (2 2)  (2 1 (2 3) ) )
// gethead (9 9)
// gettail (2 2 3 (2 2) (2 1(2 3) ) )