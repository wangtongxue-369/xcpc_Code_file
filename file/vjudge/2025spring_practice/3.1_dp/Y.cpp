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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], vis[MAXN];
ll dp[MAXN];
void solve()
{
    ll l, s, t;
    ll L;
    cin >> l;
    cin >> s >> t >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    ans = 1e18;
    if (s == t)
    {
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] % s == 0)
            {
                ans++;
            }
        }
        cout << ans << '\n';
        return;
    }
    ll base = s * t;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] - a[i - 1] >= base)
        {
            f[i] = base;
        }
        else
        {
            f[i] = a[i] - a[i - 1];
        }
        f[i] = f[i - 1] + f[i];
        vis[f[i]] = 1;
    }
    l = f[n] + base;
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= l; i++)
    {
        for (int j = s; j <= t; j++)
        {
            if (i - j >= 0)
            {
                if (vis[i])
                {
                    dp[i] = min(dp[i - j] + 1, dp[i]);
                }
                else
                {
                    dp[i] = min(dp[i - j], dp[i]);
                }
            }
        }
    }
    ans = 1e10;
    // cout << l << '\n';
    // cout << f[n] << '\n';
    for (int i = f[n]; i <= l; i++)
    {
        ans = min(ans, dp[i]);
    }
    cout << ans << '\n';
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
