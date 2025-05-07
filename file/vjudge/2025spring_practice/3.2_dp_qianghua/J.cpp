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
ll _ = 1, n, m, ans = 0, a[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    vector<vector<ll>> f(n + 10, vector<ll>(70, 0));
    for (int i = 0; i < 64; i++)
    {
        f[1][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][a[i]] = 1;
    }
    ans = 0;
    ll p = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 63; j++)
        {
            p = j & a[i];
            f[i][p] += f[i - 1][j];
            f[i][p] %= mod;
        }
        for (int j = 0; j <= 63; j++)
        {
            f[i + 1][j] += f[i][j] % mod;
        }
    }
    for (int j = 0; j <= 63; j++)
    {
        if (__builtin_popcount(j) == k)
        {
            ans += f[n][j];
            ans %= mod;
        }
    }
    cout << ans << '\n';
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