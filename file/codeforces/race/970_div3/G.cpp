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
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll g = a[1];
    for (int i = 2; i <= n; i++)
    {
        g = __gcd(g, a[i]);
    }
    if (n == 1)
    {
        cout << k - (k <= a[1]) << '\n';
        return;
    }
    if (g == 1)
    {
        cout << (n - 1) + k << '\n';
    }
    else
    {
        cout << k - 1 + min(n, (k + g - 2) / (g - 1)) << '\n';
    }
}
// 0 g 2g 3g 4g
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
