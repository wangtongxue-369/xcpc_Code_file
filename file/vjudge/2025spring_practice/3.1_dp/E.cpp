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
ll _ = 1, n, m, ans = 0, a[MAXN], f[5050];
void solve()
{
    m = 5000;
    cin >> n;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        ll x = a[i];
        // 第i种小球数量为x;
        for (int j = m; j >= x; j--)
        {
            if (j + x <= m)
            {
                // ans=ans+(j+x)/2;
                ans = (ans + ((j + x) / 2 + (j + x) % 2) * f[j] % mod) % mod;
                f[j + x] = (f[j + x] + f[j]) % mod;
            }
        }
        for (int j = x - 1; j >= 0; j--)
        {
            if (j + x <= m)
            {
                // ans=ans+(x);
                ans = (ans + x * f[j] % mod) % mod;
                f[j + x] = (f[j + x] + f[j]) % mod;
            }
        }
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
