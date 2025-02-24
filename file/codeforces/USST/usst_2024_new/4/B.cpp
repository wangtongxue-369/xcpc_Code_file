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
    ll l, r, a;
    cin >> l >> r >> a;
    if (l < r && a > 0)
    {
        ll d = (r - l);
        l += min(d, a);
        a -= min(d, a);
    }
    else if (l > r && a > 0)
    {
        ll d = (l - r);
        r += min(d, a);
        a -= min(d, a);
    }
    cout << 2 * min(l, r) + (a / 2) * 2 << '\n';
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
