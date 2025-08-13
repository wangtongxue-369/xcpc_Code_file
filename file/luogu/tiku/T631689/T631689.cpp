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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll k = 0;
ll cal(ll x)
{
    ll res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}
ll get(ll x)
{
    if (x <= 0)
    {
        return 0;
    }
    return 1 + get(x - k * cal(x));
}
void solve()
{
    ll q;
    cin >> q;
    ll x;
    while (q--)
    {
        cin >> x >> k;
        cout << get(x) << '\n';
    }
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