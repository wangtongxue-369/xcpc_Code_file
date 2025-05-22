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
    sort(a + 1, a + 1 + n);
    // cout << (ll)ceil(1.0 * (n - k) / 2) << ' ' << (ll)n - (ll)ceil(1.0 * (n - k) / 2) << ' ' << (ll)ceil(1.0 * (n - k) / 2) << '\n';
    // cout << a[(ll)ceil(1.0 * (n - k) / 2)] - a[(ll)n - (ll)ceil(1.0 * (n - k) / 2) + 1] + 1 << '\n';
    cout << a[(ll)n - (ll)ceil(1.0 * (n - k) / 2) + 1] - a[(ll)ceil(1.0 * (n - k) / 2)] + 1 << '\n';
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