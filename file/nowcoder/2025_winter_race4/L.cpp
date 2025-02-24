#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 300005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], b[MAXN];
ll q;
void solve()
{
    cin >> n >> q;
    vector<ll> a(n + 10, 0), b = a;
    vector<vector<ll>> fa(n + 10, vector<ll>(31, 0)), fb = fa;
    vector<ll> f(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        fa[i] = fa[i - 1];
        for (int w = 0; w <= 30; w++)
        {
            if ((1ll << w) & a[i])
            {
                fa[i][w]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        fb[i] = fb[i - 1];
        for (int w = 0; w <= 30; w++)
        {
            if ((1ll << w) & b[i])
            {
                fb[i][w]++;
            }
        }
    }
    for (int i = n; i >= 1; i--)
    {
        f[i] = f[i + 1];
        for (int w = 0; w <= 30; w++)
        {
            ll b1 = fb[n][w] - fb[i - 1][w];
            ll b0 = (n - i + 1) - b1;
            if (a[i] & (1 << w))
            {
                f[i] = (f[i] + (1 << w) * b0 % mod) % mod;
            }
            else
            {
                f[i] = (f[i] + (1 << w) * b1 % mod) % mod;
            }
            f[i] = f[i] % mod;
        }
    }
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        ans = ((f[l] - f[r + 1]) % mod + mod) % mod;
        for (int w = 0; w <= 30; w++)
        {
            ll a1 = fa[r][w] - fa[l - 1][w];
            ll b1 = fb[n][w] - fb[r][w];
            ll a0 = (r - l + 1) - a1;
            ll b0 = (n - r) - b1;
            ll p = (((1ll * a1 * b0 % mod + 1ll * a0 * b1 % mod) % mod) * (1ll << w)) % mod;
            // ans = (((ans - (1ll * a1 * b0 % mod + 1ll * a0 * b1 % mod) % mod) * (1ll << w)) % mod % mod + mod) % mod;
            ans = ((ans - p) % mod + mod) % mod;
        }
        cout << ans << '\n';
    }
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
