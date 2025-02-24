#include <bits/stdc++.h>
using namespace std;
// #define ll long long
#define ll unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll check(ll x)
{
    ll s = 0;
    ll p = 4;
    while (x / p != 0)
    {
        s += x / p;
        p *= 100;
        s -= x / (p / 4);
    }
    s = x - s;
    return s;
}
void solve()
{
    cin >> n;
    ll l = 0, r = 8e18;
    n += check(2024);
    // cout << check(2024) << '\n';
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid) >= n)
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
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
