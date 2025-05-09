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
ll s, t;
bool check(ll k)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        ll w = a[i] + k * b[i];
        if (w >= t)
        {
            sum += w;
        }
    }
    if (sum >= s)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void solve()
{
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll l = 0, r = 1e10;

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