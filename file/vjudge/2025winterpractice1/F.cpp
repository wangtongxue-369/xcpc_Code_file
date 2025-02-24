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
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a < 0)
    {
        a *= -1, b *= -1, c *= -1;
    }
    ll d = b * b - 4 * a * c;
    if (d < 0)
    {
        cout << "NO\n";
        return;
    }
    ll k = 1;
    for (int i = 2; i * i <= d; i++)
    {
        while (d % (i * i) == 0)
        {
            k *= i;
            d /= i * i;
        }
    }
    if (d == 1 || d == 0)
    {
        ll s = __gcd(2 * a, -b + k * d);
        if (s < 0)
        {
            s *= -1;
        }
        if (2 * a / s != 1)
        {
            cout << (-b + k * d) / s << '/' << 2 * a / s << '\n';
        }
        else
        {
            cout << (-b + k * d) / s << '\n';
        }
        return;
    }
    ll s = __gcd(-1 * b, 2 * a);
    if (s < 0)
    {
        s *= -1;
    }
    if (-b / s != 0)
    {
        cout << -b / s;
        if (2 * a / s != 1)
        {
            cout << "/" << 2 * a / s;
        }
        cout << "+";
    }
    s = __gcd(k, 2 * a);
    if (k / s != 1)
    {
        cout << k / s << '*';
    }
    cout << "sqrt(" << d << ')';
    if (2 * a / s != 1)
    {
        cout << '/' << 2 * a / s;
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _ >> m;
    while (_--)
    {
        solve();
    }
    return 0;
}
