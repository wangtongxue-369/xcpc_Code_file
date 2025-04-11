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
ll _ = 1, n, m, ans = 0, f[510][110];
struct node
{
    ll x, y;
} a[MAXN];
ll dis(ll i, ll j)
{
    return abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
}
bool cmp(node s1, node s2)
{
    if (s1.x == s2.x)
    {
        return s1.y < s2.y;
    }
    return s1.x < s2.x;
}
void solve()
{
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + 1 + n, cmp);
    ll x;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i][k] = 1;
        for (int j = 0; j <= k; j++)
        {
            for (int l = 1; l < i; l++)
            {
                if (a[l].x > a[i].x || a[l].y > a[i].y)
                {
                    continue;
                }
                x = dis(i, l) - 1;
                if (j + x <= k)
                {
                    f[i][j] = max(f[i][j], f[l][j + x] + x + 1);
                    ans = max(ans, j + f[i][j]);
                }
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