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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
ll maxn = 0;
bool check(ll x)
{
    ll minn = maxn - x;
    ll l = n + 1, r = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (a[i] < minn)
        {
            l = min(i, l);
            r = max(i, r);
        }
    }
    if (r == -1)
    {
        return 1;
    }
    ll mx = 0, mi = 1e9;
    for (int i = l; i <= r; i++)
    {
        mi = min(mi, a[i]);
        mx = max(mx, a[i]);
    }
    return mx + (minn - mi) <= maxn;
}
bool check2(ll x)
{
    ll minn = maxn - x;
    ll l = n + 1, r = -1;
    for (ll i = 1; i <= n; i++)
    {
        if (b[i] < minn)
        {
            l = min(i, l);
            r = max(i, r);
        }
    }
    if (r == -1)
    {
        return 1;
    }
    ll mx = 0, mi = 1e9;
    for (int i = l; i <= r; i++)
    {
        mi = min(mi, b[i]);
        mx = max(mx, b[i]);
    }
    return mx + (minn - mi) <= maxn;
}
void solve()
{
    maxn = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    ll ans1 = l;
    maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = 1e9 - a[i];
        maxn = max(maxn, b[i]);
    }
    l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check2(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << min(l, ans1) << '\n';
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