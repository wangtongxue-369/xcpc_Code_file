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
ll len, k;
bool check(ll x)
{
    ll sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i + 1] - a[i] <= x)
        {
            continue;
        }
        else
        {
            sum += (a[i + 1] - a[i] - 1) / x;
        }
        // sum += (a[i + 1] - a[i]) / x;
    }
    return sum <= k;
}
void solve()
{

    cin >> len >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 1, r = len;
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
