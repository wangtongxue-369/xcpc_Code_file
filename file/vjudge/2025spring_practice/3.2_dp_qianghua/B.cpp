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
ll _ = 1, n, m, ans = 0, f[MAXN];
struct node
{
    ll t, x, y;
} a[MAXN];
ll dis(ll i, ll j)
{
    return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}
bool cmp(node s1, node s2)
{
    return s1.t < s2.t;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].t >> a[i].x >> a[i].y;
    }
    ll x;
    ans = 1;
    for (int i = 1; i <= m; i++)
    {
        f[i] = 1;
        for (int j = 1; j < i; j++)
        {
            x = dis(i, j);
            if ((a[i].t - a[j].t) >= x)
            {
                f[i] = max(f[i], f[j] + 1);
                ans = max(ans, f[i]);
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}