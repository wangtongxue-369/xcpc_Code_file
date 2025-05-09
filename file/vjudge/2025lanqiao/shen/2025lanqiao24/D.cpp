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
    reverse(s.begin(), s.end());
    string s1 = s;
    reverse(s.begin(), s.end());
    // cout << s1 << '\n';
    // cout << s << '\n';
    vector<vector<ll>> dp(1010, vector<ll>(1010, 0));
    // dp[i][j]  = 考虑到s的第i位 s1的第位时，最大的相同的数量
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 1; j <= s.length(); j++)
        {
            if (s[i - 1] == s1[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << s.length() - dp[s.length()][s.length()] << '\n';
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
