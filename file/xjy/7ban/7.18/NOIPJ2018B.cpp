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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll m, p1, s1, s2;
    cin >> m >> p1 >> s1 >> s2;
    a[p1] += s1;
    ll lo = 0, hu = 0;
    for (int i = 1; i < m; i++)
    {
        lo = lo + a[i] * (m - i);
    }
    for (int i = m + 1; i <= n; i++)
    {
        hu = hu + a[i] * (i - m);
    }
    // cout << lo << ' ' << hu << '\n';
    ll pos = m, minn = abs(lo - hu);
    for (int i = 1; i <= n; i++)
    {
        if (i < m)
        {
            ll t = lo + s2 * (m - i);
            if (abs(t - hu) < minn)
            {
                pos = i;
                minn = abs(t - hu);
            }
        }
        if (i > m)
        {
            ll h = hu + s2 * (i - m);
            if (abs(lo - h) < minn)
            {
                pos = i;
                minn = abs(lo - h);
            }
        }
    }
    cout << pos << '\n';
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