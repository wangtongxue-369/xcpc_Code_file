#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 300005;
int _ = 1, n, m, ans = 0; // a[MAXN], b[MAXN], f[MAXN];
long long a[MAXN], b[MAXN], f[MAXN];
void solve()
{
    ll maxn = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
        f[i] = f[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    if (maxn > b[1])
    {
        cout << "-1" << '\n';
        return;
    }
    // dp[i][j]
    vector<vector<int>> dp(n + 10, vector<int>(m + 10, INF));
    fill(dp[0].begin(), dp[0].end(), 0);
    vector<vector<int>> dp2(n + 10, vector<int>(m + 10, INF));
    fill(dp2[0].begin(), dp2[0].end(), 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] > b[j])
            {
                break;
            }
            ll l = 1, r = i;
            while (l < r)
            {
                ll mid = (l + r) >> 1;
                if (f[i] - f[mid - 1] <= b[j])
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            dp[i][j] = min(dp2[l - 1][j] + (m - j), dp[i][j]);
        }
        for (int j = 1; j <= m; j++)
        {
            dp2[i][j] = min(dp2[i][j - 1], dp[i][j]);
        }
    }
    ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++)
    {
        ans = min(ans, dp[n][i]);
    }

    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
