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
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    priority_queue<PII, vector<PII>, greater<PII>> q;
    vector<vector<ll>> dp(2, vector<ll>(n + 10, 0));
    vector<vector<ll>> f(2, vector<ll>(n + 10, 0));
    dp[0][0] = 1;
    ll x = 10;
    // queue<pair<ll, ll>> q;
    q.emplace(0, 0);
    while (!q.empty())
    {
        auto [i, j] = q.top();
        q.pop();
        if (f[i][j] == 1)
        {
            continue;
        }
        //>
        if (s[i][j + 1] == '>')
        {
            dp[i][j + 1 + 1] = 1;
            q.emplace(i, j + 1 + 1);
        }
        //<
        if (j >= 2 && s[i][j - 1] == '<')
        {
            dp[i][j - 1 - 1] = 1;
            q.emplace(i, j - 1 - 1);
        }
        // up
        if (i == 1 && s[i - 1][j] == '>')
        {
            dp[i - 1][j + 1] = 1;
            q.emplace(i - 1, j + 1);
        }
        if (i == 1 && s[i - 1][j] == '<')
        {
            dp[i - 1][j - 1] = 1;
            q.emplace(i - 1, j - 1);
        }
        // down
        if (i == 0 && s[i + 1][j] == '>')
        {
            dp[i + 1][j + 1] = 1;
            q.emplace(i + 1, j + 1);
        }
        if (i == 0 && s[i + 1][j] == '<')
        {
            dp[i + 1][j - 1] = 1;
            q.emplace(i + 1, j - 1);
        }
        f[i][j] = 1;
    }
    // for (int i = 0; i <= 1; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if (dp[1][n - 1] == 1 || dp[0][n - 1] == 1 || dp[1][n - 1 - 1] == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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
