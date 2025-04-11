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
ll ask(ll c, ll r)
{
    ll x;
    cout << "? " << c << ' ' << r << endl;
    cin >> x;
    return x;
}
void solve()
{
    cin >> n;
    ll c, p;
    p = ask(n, 1);
    ll b;
    for (ll i = 1; i * i <= n; i++)
    {
        ll v = ask(i, p);
        a[v] = i;
        b = i;
        if (v == p)
        {
            cout << "! " << i - a[v] << ' ' << p << endl;
            return;
        }
    }
    for (ll i = b;; i += b)
    {
        ll v = ask(i, p);
        if (a[v])
        {
            cout << "! " << i - a[v] << ' ' << p << endl;
            return;
        }
    }
}
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}