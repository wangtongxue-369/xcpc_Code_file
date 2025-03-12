#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll c[200][200];
ll C(ll n1, ll m1)
{
    if (n1 < m1)
    {
        return 0;
    }
    if (n1 == 0 || m1 == 0)
    {
        return 1;
    }
    if (c[n1][m1] != 0)
    {
        return c[n1][m1];
    }
    return c[n1][m1] = (C(n1 - 1, m1) + C(n1 - 1, m1 - 1)) % mod;
}
void solve()
{
    ll k;
    cin >> n >> k >> m;
    string s, t;
    cin >> s >> t;
    ll p = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            p++;
        }
    }
    vector<vector<ll>> dp(k + 5, vector<ll>(n + 5, 0));
    dp[0][p] = 1;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int x = 0; x <= m; x++) // 这一轮熄灭的灯为x个
            {
                // 那就有m-x的灯是亮的
                // 现在是j个亮，n-j个不亮
                //
                if (x <= j && n - j >= m - x)
                {
                    ll res = dp[i][j] * c[j][x] % mod;
                    dp[i + 1][j - x + (m - x)] += res * c[n - j][m - x] % mod;
                    dp[i + 1][j - x + (m - x)] %= mod;
                }
            }
        }
    }
    cout << dp[k][0] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i <= 150; i++)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            C(i, j);
        }
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
