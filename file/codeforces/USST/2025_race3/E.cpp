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
ll _ = 1, n, m, ans = 0, c[MAXN], d[MAXN];
struct node
{
    ll a, b;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.b - s1.a < s2.b - s2.a;
}
void solve()
{
    ll sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].b;
        sum += a[i].b;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        c[i] += c[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
        d[i] += d[i - 1];
    }
    sort(a + 1, a + 1 + n, cmp);
    ans = 1e18;
    a[0].b = 0;
    a[0].a = 0;
    ll sum1 = 0;
    ans = sum + d[n];
    d[n + 1] = 0;
    c[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        sum1 += a[i].a;
        sum -= a[i].b;
        ans = min(ans, sum + sum1 + d[i - 1] + c[n - i + 1]);
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