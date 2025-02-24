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
    ll t, k;
    cin >> n >> t >> k;
    cout << min((n - k) / t, k + 1) << '\n';
    // ll maxn = 0;
    // ll mren;
    // if (n < t)
    // {
    //     maxn = 0;
    //     mren = 0;
    //     cout << 0 << '\n';
    //     return;
    // }
    // else
    // {
    //     maxn = (n - t) / (t + 1) + 1;
    //     mren = maxn - 1;
    // }

    // ll yu = n - (mren + maxn * t);

    // if (mren == k)
    // {
    //     cout << maxn << '\n';
    //     return;
    // }
    // if (mren < k)
    // {
    //     cout << maxn << ' ' << yu << ' ' << mren << '\n';
    //     cout << maxn - (ll)ceil(1.0 * max(((k - mren) - yu), 0ll) / t) << '\n';
    // }
    // else
    // {

    //     cout << maxn - (mren - k) << '\n';
    // }
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
