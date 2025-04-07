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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    double kc;
    double sj;
    double dsj;
} a[MAXN];
bool cmp(node s1, node s2)
{
    return s1.dsj > s2.dsj;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].kc;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].sj;
        a[i].dsj = 1.0 * a[i].sj / (1.0 * a[i].kc);
    }
    sort(a + 1, a + 1 + n, cmp);
    ll i = 1;
    double sum = 0;
    while (m != 0 && (i <= n))
    {
        if (a[i].kc <= m)
        {
            sum += a[i].sj;
            m -= a[i].kc;
            i++;
        }
        else
        {
            sum += a[i].dsj * m;
            m = 0;
        }
    }
    cout << fixed << setprecision(2) << sum << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
