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
ll get(ll x, ll p)
{
    ll res = 0;
    ll e = 1;
    while (x)
    {
        res += (x % 10) * e;
        x /= 10;
        e *= p;
    }
    return res;
}
void solve()
{
    // cout << get(42, 13) << '\n';
    ll p, q, r;
    cin >> p >> q >> r;
    string s = to_string(p) + to_string(q) + to_string(r);
    ll maxn = 0;
    for (auto it : s)
    {
        maxn = max(maxn, (ll)(it - '0'));
    }
    for (int i = maxn + 1; i <= 16; i++)
    {
        if (get(p, i) * get(q, i) == get(r, i))
        {
            cout << i << '\n';
            return;
        }
    }
    cout << 0 << '\n';
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
