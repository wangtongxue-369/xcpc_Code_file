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
void solve()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b - a > d - c)
    {
        cout << b << ' ' << d << '\n';
        cout << b - 1 << ' ' << d << '\n';
        cout << a << ' ' << d - 1 << '\n';
    }
    else
    {
        cout << b << ' ' << d << '\n';
        cout << b << ' ' << d - 1 << '\n';
        cout << b - 1 << ' ' << c << '\n';
    }
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
