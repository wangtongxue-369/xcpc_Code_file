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
    ll t;
    cin >> t;
    ll l, r;
    while (t--)
    {
        cin >> l >> r;
        if (r < 2 * l)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << (r - 2 * l + 1) * (r - 2 * l + 2) / 2 << '\n';
    }
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