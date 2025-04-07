#include <bits/stdc++.h>
using namespace std;
#define ll __int128_t
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 600005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll x[MAXN], y[MAXN];
void solve()
{
    long long t;
    cin >> t;
    n = t;
    ll xc, yc, rc;
    cin >> t;
    xc = t;
    cin >> t;
    yc = t;
    cin >> t;
    rc = t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        x[i] = t;
        cin >> t;
        y[i] = t;
    }
    function<PII(ll x1, ll y1, ll x2, ll y2)> xl = [&](ll x1, ll y1, ll x2, ll y2) -> PII
    {
        // 从圆心出发 圆心，点
        return {x2 - x1, y2 - y1};
    };
    function<ll(PII s1, PII s2)> xx = [&](PII s1, PII s2)
    {
        return s1.first * s2.second - s2.first * s1.second;
    };
    function<ll(PII s1, PII s2)> get = [&](PII s1, PII s2)
    {
        ll asd = s1.first * s2.second - s2.first * s1.second;
        if (asd < 0)
        {
            asd *= -1;
        }
        return asd;
    };
    ll snow = 0;
    ll r = 1;
    ans = 0;
    for (int l = 0; l < n; l++)
    {
        while (1)
        {
            ll net = (r + 1) % n;
            ll s = xx(xl(xc, yc, x[l], y[l]), xl(xc, yc, x[net], y[net]));
            if (s <= 0)
            {
                break;
            }
            if (s * s < rc * rc * ((x[l] - x[net]) * (x[l] - x[net]) + (y[l] - y[net]) * (y[l] - y[net])))
            {
                break;
            }
            s = get(xl(x[l], y[l], x[r], y[r]), xl(x[l], y[l], x[net], y[net]));
            snow += s;
            ans = max(ans, snow);
            r = net;
        }
        ans = max(ans, snow);
        ll s = get(xl(x[l], y[l], x[l + 1], y[l + 1]), xl(x[l], y[l], x[r], y[r]));
        snow -= s;
    }
    cout << (long long)ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
