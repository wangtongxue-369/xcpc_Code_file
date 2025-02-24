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
void solve()
{
    ll x, y;
    cin >> n >> x >> y;
    ll sum = 0;
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        ve.push_back(a[i]);
    }
    sort(a + 1, a + 1 + n);
    sort(ve.begin(), ve.end());
    ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll left = sum - ve[i] - y;
        ll right = sum - ve[i] - x;
        ll l = lower_bound(ve.begin(), ve.end(), left) - ve.begin();
        ll r = upper_bound(ve.begin(), ve.end(), right) - ve.begin();
        if (l == n)
        {
            continue;
        }
        l = max(l, (ll)i + 1);
        r--;
        if (r <= i || r < l)
        {
            continue;
        }
        ans += (r - l + 1);
    }
    cout << ans << '\n';
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
