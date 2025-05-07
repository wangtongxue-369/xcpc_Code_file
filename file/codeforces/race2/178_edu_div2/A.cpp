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
    ll a, b, c;
    cin >> a >> b >> c;
    ll p = (a + b + c);
    if (p % 3 != 0)
    {
        cout << "NO\n";
        return;
    }
    p /= 3;
    if (a > p || b > p || c < p)
    {
        cout << "NO\n";
        return;
    }
    ll p1 = p - a;
    ll p2 = p - a;
    if (p1 + p2 < c)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
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