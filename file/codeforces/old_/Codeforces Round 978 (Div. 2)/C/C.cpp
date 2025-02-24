#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0;
ll dp[100500][10];
ll a[10][100500];
bool c1(ll i)
{
    return a[1][i] + a[1][i + 1] + a[2][i] >= 1;
}
bool c2(ll i)
{
    return a[1][i] + a[1][i - 1] + a[2][i] >= 1;
}
bool c3(ll i)
{
    return a[1][i] + a[2][i] + a[2][i + 1] >= 1;
}
bool c4(ll i)
{
    return a[1][i] + a[2][i] + a[2][i - 1] >= 1;
}
bool c5(ll i, ll j)
{
    return a[i][j] + a[i][j + 1] + a[i][j + 2] >= 1;
}
void solve()
{
    cin >> n;
    char c;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == 'A')
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = -1;
            }
        }
    }
    for (int i = 3; i <= n; i += 3)
    {
        dp[i][0] = 0, dp[i][1] = 0, dp[i][2] = 0;
        dp[i][0] = dp[i - 3][0] + c2(i) + c3(i - 2);
        dp[i][0] = max(dp[i][0], dp[i - 3][0] + c1(i - 2) + c4(i));
        dp[i][0] = max(dp[i][0], dp[i - 3][0] + c5(1ll, i - 2) + c5(2ll, i - 2));
        if (i >= 4)
        {
            dp[i][1] = max(dp[i][1], dp[i - 3][1] + c5(1, i - 3) + c5(2, i - 4));
            dp[i][2] = max(dp[i][2], dp[i - 3][2] + c5(1, i - 4) + c5(2, i - 3));
        }
        if (i >= 6)
        {
            dp[i][1] = max(dp[i][1], dp[i - 6][0] + c1(i - 5) + c5(1, i - 3) + c5(2, i - 4));
            dp[i][2] = max(dp[i][2], dp[i - 6][0] + c3(i - 5) + c5(1, i - 4) + c5(2, i - 3));
        }
        dp[i][0] = max(dp[i][0], dp[i][1] + c4(i));
        dp[i][0] = max(dp[i][0], dp[i][2] + c2(i));
    }
    cout << dp[n][0] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << (_ == 1) ? 1 : 0;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
