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
double a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    double sum = 0, maxn = 0, minn = 1e9;
    ll u, v;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i];
        if (a[i] > maxn)
        {
            maxn = max(maxn, a[i]);
            u = i;
        }
        if (a[i] < minn)
        {
            minn = min(minn, a[i]);
            v = i;
        }
    }
    sum -= (maxn + minn);
    double p = sum / (1.0 * (n - 2));
    double w = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == u || i == v)
        {
            continue;
        }
        w = max(w, abs(p - a[i]));
    }
    printf("%.2lf %.2lf", p, w);
    // cout << p << ' ' << w << '\n';
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
