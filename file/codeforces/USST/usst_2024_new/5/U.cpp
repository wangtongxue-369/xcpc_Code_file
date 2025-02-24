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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
ll c, k, d;
bool check(ll x)
{
    vector<ll> f(n + 10, 0);
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= x)
        {
            sum++;
        }
    }
    if (sum >= k)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < x)
        {
            ll l = max(0ll, i - m + 1);
            ll maxn = a[i] + c + d * (i - l);
            if (maxn < x)
            {
                continue;
            }
            ll minn = a[i] + c;
            ll p;
            if (d == 0)
            {
                p = 0;
            }
            else
            {
                p = (ll)ceil(1.0 * (x - minn) / (1.0 * d));
            }
            p = max(p, 0ll);
            ll r = i - p;
            f[l]++;
            f[r + 1]--;
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
        res = max(res, f[i]);
    }
    if (sum + res >= k)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k >> m >> c >> d;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 0, r = 1e18;
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
    cout << l << '\n';
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
