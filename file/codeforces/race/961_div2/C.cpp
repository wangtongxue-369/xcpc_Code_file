#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    ll a, c;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.a < s2.a;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].c;
    }
    sort(a + 1, a + 1 + n, cmp);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != n && abs(a[i].a - a[i + 1].a) == 1)
        {
            ll tmp = a[i].a * a[i].c + a[i + 1].a * a[i + 1].c;
            if (tmp < m)
            {
                ans = max(ans, tmp);
                continue;
            }
            ll a1 = min(m / a[i].a, a[i].c);
            tmp = a[i].a * a1;
            ll b1 = min(a[i + 1].c, (m - tmp) / a[i + 1].a);
            tmp += a[i + 1].a * b1;
            if (a1 > 0 && b1 < a[i + 1].c && tmp < m)
            {
                ll s = min({a1, a[i + 1].c - b1, m - tmp});
                tmp += s;
            }
            ans = max(ans, tmp);
        }
        else
        {
            ll a1 = min(a[i].c, m / a[i].a);
            ans = max(ans, a1 * a[i].a);
            continue;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
