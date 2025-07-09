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
    ll s;
    cin >> n >> s;
    ans = 0;
    ll dx, dy, x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> dx >> dy >> x >> y;
        if (dx == dy && (y - x) % s == 0)
        {
            ans++;
            continue;
        }
        if (dx != dy && (x + y) % s == 0)
        {
            ans++;
            continue;
        }
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