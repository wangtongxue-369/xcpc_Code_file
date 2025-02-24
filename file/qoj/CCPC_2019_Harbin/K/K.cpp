#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
double a[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        double d = 1.0 * a[i] + (1.0 * k / sum) * (1.0 * a[i]);
        printf("%.6lf ", d);
    }
    printf("\n");
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
