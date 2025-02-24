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
double _ = 1, n, m, ans = 0;
double a[MAXN], b[MAXN];
void solve()
{
    ll p;
    cin >> n >> p;
    double s = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        s += a[i];
    }
    if (s <= p)
    {
        cout << -1 << '\n';
        return;
    }
    function<bool(double x)> check = [&](double x)
    {
        double sum = 0, t;
        for (int i = 1; i <= n; i++)
        {
            // k = (1.0*b[i]/(1.0*a[i]));
            t = x * a[i];
            if (x * a[i] <= b[i])
            {
                continue;
            }
            else
            {
                sum += (a[i] * x - b[i]);
            }
        }
        return sum <= x * p;
    };
    double l = 0, r = 1e10;
    while (r - l > 1e-6)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << '\n';
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
