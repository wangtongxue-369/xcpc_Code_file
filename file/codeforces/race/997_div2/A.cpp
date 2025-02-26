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
ll _ = 1, n, m, ans = 0, a[2050][2050], f[MAXN];
void solve()
{
    cin >> n >> m;
    ll x, y;
    ll px = 1, py = 1;
    ll minx = 1e9, maxx = 0;
    ll miny = 1e9, maxy = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        px += x;
        py += y;
        if (i == 1)
        {
            minx = px;
            miny = py;
            maxx = px + m - 1;
            maxy = py + m - 1;
        }
        else
        {
            maxx = max(maxx, px + m - 1);
            maxy = max(maxy, py + m - 1);
        }
    }
    // cout << maxx << " " << minx << ' ' << maxy << ' ' << miny << '\n';
    cout << 2 * ((maxx - minx + 1) + (maxy - miny + 1)) << '\n';
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
