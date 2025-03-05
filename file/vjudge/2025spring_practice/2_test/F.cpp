#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define double long double
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0;
// double a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    vector<double> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double l = 0, r = 1e9;
    ll x = 1000;
    while (x--)
    {
        double mid = (l + r) / 2;
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += (1.0 * a[i] * mid) / (1.0 * a[i] * mid + 1.0);
        }
        // cout << sum << '\n';
        double cnt = sum - 1.0 * k;
        if (cnt < 0)
        {
            cnt = -cnt;
        }
        if (sum > k || cnt < 1e-12)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    // cout << l << '\n';
    // cout << fixed << setprecision(13);
    for (int i = 0; i < n; i++)
    {
        double x = (1.0 * l * a[i]) / (a[i] * l + 1.0);
        // printf("%.16lf\n", x);
        cout << fixed << setprecision(13) << x << '\n';
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    //  cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
