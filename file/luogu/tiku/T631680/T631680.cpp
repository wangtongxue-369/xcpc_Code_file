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
void f(ll a, ll b)
{
    if (a == 0 && b == 0)
    {
        ans++;
        return;
    }
    if (a)
    {
        f(a - 1, b);
    }
    if (b)
    {
        f(a, b - 1);
    }
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    f(a, b);
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}