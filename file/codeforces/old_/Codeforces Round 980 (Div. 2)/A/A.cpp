#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll a, b;
    cin >> a >> b;
    if (a >= b)
    {
        cout << a << '\n';
        return;
    }
    else
    {
        ll x = b - a;
        ll x1 = x / 2;
        cout << max(0ll, a - x) << '\n';
    }
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
