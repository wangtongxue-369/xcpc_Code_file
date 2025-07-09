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
ll _ = 1, n, m, ans = 0; // a[MAXN], s[MAXN];
struct node
{
    ll a, s;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.s < s2.s;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].a;
    }
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i].a;
    }
    sum /= n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].s == m)
        {
            if (a[i].a < 60)
            {
                a[i].a = 60;
            }
        }
        else
        {
            if (1.0 * a[i].a >= sum)
            {
                a[i].a -= 2;
                a[i].a = max(0ll, a[i].a);
            }
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i].a << ' ';
    }
    cout << '\n';
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