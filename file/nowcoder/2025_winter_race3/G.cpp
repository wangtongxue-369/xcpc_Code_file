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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], k;
bool check(ll s)
{
    ll da = 0, de = 0;
    ll l = 1, r, len;
    ll d = 1, a0 = 0;
    ll res = 0;
    for (l = 1; l <= n; l = r + 1)
    {
        r = n / (n / l);
        len = r - l + 1;
        a0 = n % l;
        d = -1 * n / l;
        // cout << l << ' ' << r << ' ' << a0 << ' ' << a0 + (len - 1) * d << '\n';
        if (a0 < s)
        {
            continue;
        }
        ll x = (s - a0) / d + 1;
        // cout << l << ' ' << r << ' ' << a0 << ' ' << a0 + (len - 1) * d << ' ' << x << '\n';
        res += x;
    }
    // cout << s << ' ' << res << '\n';
    if (res >= k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// 找到第一个大于等于mid的数的数量大于等于k的数
void solve()
{
    cin >> n >> k;
    // check(2);
    //  return;
    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    // cout << l << '\n';
    ll s = l;
    ll d = 1, len, a0;
    ans = 0;
    ll res = 0, tot = 0;
    s++;
    for (l = 1; l <= n; l = r + 1)
    {
        r = n / (n / l);
        len = r - l + 1;
        a0 = n % l;
        d = -1 * n / l;
        if (a0 < s)
        {
            continue;
        }
        ll x = (s - a0) / d + 1;
        res += x;
        ans += (a0 + (a0 + (x - 1) * d)) * x / 2;
        // cout << l << ' ' << r << ' ' << a0 << ' ' << a0 + (x - 1) * d << ' ' << x << '\n';
    }
    s--;
    // cout << ans << '\n';
    ans += s * (k - res);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
