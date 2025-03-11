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
ll lcm(ll s1, ll s2)
{
    return s1 * s2 / __gcd(s1, s2);
}
void solve()
{
    ll a, b;
    cin >> n >> a >> b;
    cout << n - (n / a) - (n / b) + 2 * (n / (lcm(a, b))) << '\n';
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
