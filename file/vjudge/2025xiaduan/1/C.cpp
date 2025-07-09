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
ll ksm(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve()
{
    ll q;
    cin >> n >> q;
    vector<ll> a(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    };
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        ll p = (a[r] - a[l - 1]) / 2 + a[l - 1];
        ll t = lower_bound(a.begin() + l, a.begin() + r + 1, p) - a.begin();
        ans = 0;
        for (int j = -1; j <= 1; j++)
        {
            ll L = j + t;
            if (l <= (L) && (L) <= r)
            {
                ans = max(ans, (a[r] - a[L]) * (a[L] - a[l - 1]));
            }
        }
        ans %= mod;
        ans = ((a[r] - a[l - 1]) % mod) * ksm(ans, mod - 2) % mod;
        cout << ans << ' ';
    }
    cout << '\n';
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