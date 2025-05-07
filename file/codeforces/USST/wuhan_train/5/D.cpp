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
ll _ = 1, n, m, a[MAXN], pr[MAXN], f[5100][10050];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // pr[i] = pr[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll l = 0, r = 0;
        for (int j = 0; j <= 2 * n; j++)
        {
            if (i - j >= 1)
                l += a[i - j];
            if (j + i <= n)
                r += a[i + j];
            f[i][j] = max(l, r);
        }
    }
    for (int j = 1; j <= 2 * n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i - 1 >= 1)
                f[i][j] = max(f[i][j], f[i - 1][j - 1]);
            if (i + 1 <= n)
                f[i][j] = max(f[i][j], f[i + 1][j - 1]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll res = 0;
        for (int j = 1; j <= 2 * n; j++)
        {
            res ^= j * f[i][j];
        }
        ans ^= (i + res);
    }
    cout << ans;
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