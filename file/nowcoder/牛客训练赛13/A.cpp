#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 2000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, a[MAXN], f[MAXN];
bool cmp(ll s1, ll s2)
{
    return s1 > s2;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        cout << "0.00\n";
        return;
    }
    sort(a + 1, a + 1 + n, cmp);
    double ans = 0;
    double l = a[1], r = a[1];
    for (int i = 2; i <= n; i++)
    {
        double s1 = 1.0 * a[i] + 1.0 * abs(l - a[i]) / 2;
        double s2 = 1.0 * a[i] + 1.0 * abs(r - a[i]) / 2;
        if (s1 >= s2)
        {
            ans += s1;
            l = a[i];
        }
        else
        {
            r = a[i];
            ans += s2;
        }
    }
    printf("%.2lf\n", ans);
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
