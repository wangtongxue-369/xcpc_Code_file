/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
const double pi = acos(-1);
void solve()
{
    double a, b, x1, x2, y1, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    double dx = x2 - x1, dy = y2 - y1;
    double k = dy / dx;
    double c = y1 - k * x1;
    double A = 1 / (a * a) + k * k / (b * b);
    double B = 2 * k * c / (b * b);
    double C = c * c / (b * b) - 1;
    double DD = B * B - 4 * A * C;
    if (DD < 1e-6)
    {
        cout << -1 << '\n';
        return;
    }
    double xl = (-B - sqrt(DD)) / (2 * A), xr = (-B + sqrt(DD)) / (2 * A);
    if (xl > xr)
    {
        swap(xl, xr);
    }
    n = 5000;
    dx = (xr - xl) / (1.0 * n);
    double S = 0;
    function<double(double x)> get = [&](double x)
    {
        return b * sqrt(1 - x * x / (a * a));
    };
    for (int i = 0; i < n; i++)
    {
        double x1 = xl + i * dx;
        double x2 = x1 + dx;
        double y1 = get(x1);
        double y2 = get(x2);
        double yy1 = k * x1 + c;
        double yy2 = k * x2 + c;
        double ss = 0.5 * ((y1 - yy1) + (y2 - yy2)) * dx;
        S += fabs(ss);
    }
    double ts = pi * a * b;
    double ss = ts - S;
    if (ss < S)
    {
        swap(ss, S);
    }
    double an = S / ss;

    cout << fixed << setprecision(10) << an << '\n';
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