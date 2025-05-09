#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 10000500;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll ge(ll i)
{
    // return (1 + i) * i / 2;
    // return i * (i + 1) / 6 * (i + 2) / 6;
    return f[i];
}
ll get(ll l, ll r)
{
    ll t1 = 1, t2 = 10000000;
    while (t1 < t2)
    {
        ll mid = (t1 + t2 + 1) >> 1;
        // cerr << mid << '\n';
        if ((((1 + (mid)) * (mid)) / 2) - mid + 1 <= l)
        {
            t1 = mid;
        }
        else
        {
            t2 = mid - 1;
        }
    }
    ll p1 = t1;
    ll pt1 = l - (((1 + p1) * p1 / 2) - p1 + 1) + 1;
    t1 = 1, t2 = 10000000;
    while (t1 < t2)
    {
        ll mid = (t1 + t2 + 1) >> 1;
        if ((((1 + (mid)) * (mid)) / 2) - mid + 1 <= r)
        {
            t1 = mid;
        }
        else
        {
            t2 = mid - 1;
        }
    }
    ll p2 = t1;
    ll pt2 = r - (((1 + p2) * p2 / 2) - p2 + 1) + 1;
    ll res = 0;
    // cout << p1 << ' ' << pt1 << ' ' << p2 << ' ' << pt2 << '\n';
    res -= ge(p1 - 1);
    // cout << ge(p1 - 1) << '\n';
    res -= (1 + (pt1 - 1)) * (pt1 - 1) / 2;
    // cout << (1 + (pt1 - 1)) * (pt1 - 1) / 2 << '\n';
    res += ge(p2 - 1);
    // cout << ge(p2 - 1) << '\n';
    res += (1 + (pt2)) * pt2 / 2;
    // cout << (1 + (pt2)) * pt2 / 2 << '\n';
    return res;
}
void solve()
{
    for (ll i = 1; i <= 10000500; i++)
    {
        f[i] = f[i - 1] + (1 + i) * i / 2;
    }
    ll t;
    cin >> t;
    ll l, r;
    while (t--)
    {
        cin >> l >> r;
        cout << get(l, r) << '\n';
    }
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