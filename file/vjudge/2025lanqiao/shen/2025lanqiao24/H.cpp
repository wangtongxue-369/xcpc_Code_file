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
ll _ = 1, n, m, ans = 0, h[MAXN], w[MAXN];
ll k;
bool check(ll x)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (h[i] / x) * (w[i] / x);
    }
    if (sum >= k)
    {
        return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> w[i];
    }
    ll l = 1, r = 1e5;
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
