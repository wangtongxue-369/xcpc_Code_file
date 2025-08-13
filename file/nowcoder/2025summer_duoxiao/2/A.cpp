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
void solve()
{
    cin >> n;
    ll sumd = 0, sums = 0;
    ll sumf = 0;
    bool flag = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
        {
            sumf++;
        }
    }
    vector<array<ll,3> > dp(n+10);
    if (a[1]==-1)
    {
        dp[1][1]=1,dp[1][0]=0;
    }
    else if (a[1]==1)
    {
        dp[1][1]=1;
    }else if (a[1]==0)
    {
        dp[1][0]=0;
    }
    for (int i=2;i<=n;i++)
    {
        
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i <= 500002; i++)
    {
        f[i] = f[i - 1] * 2;
        f[i] %= mod;
    }
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}