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
ll _ = 1, n, m, ans = 0, a[MAXN], f[100050], c[MAXN], h[MAXN];
void solve()
{
    ll x;
    cin >> n >> x;
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> h[i];
        maxn += h[i];
    }
    for (int i = 0; i <= maxn + 10; i++)
    {
        f[i] = 2e18;
    }
    ans = 0;
    f[0] = 0;
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = maxn; j >= 0; j--)
        {
            if (j - h[i] >= 0 && f[j - h[i]] <= 1e18 && (i - 1) * x - f[j - h[i]] >= c[i])
            {
                f[j] = min(f[j], f[j - h[i]] + c[i]);
                ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';
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
