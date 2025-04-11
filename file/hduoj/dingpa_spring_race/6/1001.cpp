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
ll _ = 1, n, m, ans = 0;
ll vis[10];
ll k, s1, s2, s3;
ll a, b, c;
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    cin >> k >> a >> b >> c;
    memset(vis, 0, sizeof(vis));
    ans = k;

    if (k >= a)
    {
        ans = min(ans, k - a);
    }
    if (k >= b)
    {
        ans = min(ans, k - b);
    }
    if (k >= c)
    {
        ans = min(ans, k - c);
    }
    if (k >= a + b)
    {
        ans = min(ans, k - a - b);
    }
    if (k >= a + c)
    {
        ans = min(ans, k - a - c);
    }
    if (k >= b + c)
    {
        ans = min(ans, k - b - c);
    }
    if (k >= a + b + c)
    {
        ans = min(ans, k - a - b - c);
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