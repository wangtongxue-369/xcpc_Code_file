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
ll _ = 1, n, m, ans = 0, a[MAXN], f[105][105 * 100];
ll fac[200];
void solve()
{
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2)
    {
        cout << 0 << '\n';
        return;
    }
    fac[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i;
        fac[i] %= mod;
    }
    // cout << fac[3] << '\n';
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 10000; k >= 0; k--)
        {
            for (int j = 1; j <= i; j++)
            {
                if (k - a[i] >= 0)
                {
                    f[j][k] += f[j - 1][k - a[i]];
                    f[j][k] %= mod;
                }
            }
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += f[i][sum / 2] * (fac[i] * fac[n - i] % mod) % mod;
        ans %= mod;
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
