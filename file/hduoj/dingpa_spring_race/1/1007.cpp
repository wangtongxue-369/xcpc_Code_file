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
ll _ = 1, n, m, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    __int128_t ans = 0;
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    ll x = n / 2;
    ans = ((2 + x * 2) * x) / 2;
    ans %= mod;
    cout << (ll)ans << '\n';
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
