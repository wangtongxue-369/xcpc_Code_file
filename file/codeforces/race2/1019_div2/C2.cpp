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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], pref[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    f[0] = 0;
    f[n + 1] = 0;
    f[n + 2] = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= k)
        {
            f[i] = 1;
        }
        else
        {
            f[i] = -1;
        }
    }
    ll l0 = 1e18, l1 = 1e18;
    for (int i = 2; i < n; i++)
    {
        ll l = i - 1;
        ll le = i - 1;
        ll d = 2 * pref[le] - (le);
        ll vp = d % 1;
        if (vp % 2 == 1)
        {
            if (le % 2 == 1)
            {
                l1 = min(l1, d);
            }
        }
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