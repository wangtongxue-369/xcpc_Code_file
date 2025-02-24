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
bool check(ll x)
{
    ll p = 0;
    ll d = 1;
    for (int i = 1; i <= n; i++)
    {
        if (p + a[i] <= x)
        {
            p += a[i];
        }
        else
        {
            p = a[i];
            d++;
        }
    }
    if (d > m)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    cin >> n >> m;
    ll l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = max(l, a[i]);
        r += a[i];
    }
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
