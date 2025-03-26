#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, x[MAXN], y[MAXN];
ll a[MAXN], b[MAXN];
void solve()
{
    cin >> n >> m;
    ll minU = 1e18, maxU = -1e18, minV = 1e18, maxV = -1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        ll u = x[i] + y[i], v = x[i] - y[i];
        minU = min(minU, u);
        maxU = max(maxU, u);
        minV = min(minV, v);
        maxV = max(maxV, v);
    }
    ans = 1e18;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i];
        ll u = a[i] + b[i];
        ll v = a[i] - b[i];
        ans = min(ans, max({abs(u - minU), abs(u - maxU), abs(v - minV), abs(v - maxV)}));
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
