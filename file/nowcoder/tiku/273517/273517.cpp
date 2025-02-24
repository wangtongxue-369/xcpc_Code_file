#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
ll k; // a[MAXN], f[MAXN];

// 考虑到i时，长度为j的答案
// dp[i][j]=dp[i-1][j-1]*10+a[i]
struct node
{
    ll f;
    ll c = 0;
};
node f[1010][1010];
ll C[1010][1010];
ll c(ll n1, ll m1)
{
    if (n1 < m1)
    {
        return 0;
    }
    if (n1 == 0 || m1 == 0)
    {
        return 1;
    }
    if (C[n1][m1] != 0)
    {
        return C[n1][m1];
    }
    return C[n1][m1] = (c(n1 - 1, m1) + c(n1 - 1, m1 - 1)) % mod;
}
void solve()
{

    cin >> n >> k;
    for (int i = 0; i <= n; i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            c(i, j);
        }
    }
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i][j].f = (f[i - 1][j].f % mod + (f[i - 1][j - 1].f * 10) % mod + ((s[i] - '0') * c(i - 1, j - 1)) % mod) % mod;
        }
    }
    cout << f[n][k].f % mod << '\n';
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
