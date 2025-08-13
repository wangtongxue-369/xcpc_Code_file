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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        ll b = a[i] - c;
        ll l = lower_bound(a + 1, a + 1 + n, b) - a;
        ll r = upper_bound(a + 1, a + 1 + n, b) - a - 1;
        // cout << i << ' ' << l << ' ' << r << ' ' << b << '\n';
        if (a[l] == b)
        {
            ans += r - l + 1;
            // cout << i << ' ' << l << ' ' << r << ' ' << b << '\n';
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}