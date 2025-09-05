/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r
ll tr[200005 << 2]; // lazy[200005 << 2];
void build(ll k, ll l, ll r)
{
    if (l == r)
    {
        tr[k] = 0;
        return;
    }
    ll mid = (l + r) >> 1;
    build(lson), build(rson);
    tr[k] = __gcd(tr[k << 1], tr[k << 1 | 1]);
}
void upd(ll k, ll l, ll r, ll p, ll z)
{
    if (l == p && r == p)
    {
        tr[k] = z;
        return;
    }
    ll mid = (l + r) >> 1;
    if (p <= mid)
    {
        upd(lson, p, z);
    }
    if (p > mid)
    {
        upd(rson, p, z);
    }
    tr[k] = __gcd(tr[k << 1], tr[k << 1 | 1]);
}
ll get(ll x)
{
    if (x == 0)
    {
        return n;
    }
    ll sum = 0;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            sum += 2;
        }
        if (i * i == x)
        {
            sum--;
        }
    }
    return sum;
}
void solve()
{
    // cout << __gcd(100, 0) << '\n';
    ll q;
    cin >> n >> q;
    build(1, 1, n);
    a[0] = -100, a[n + 1] = 2e9 + 10;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > a[i + 1])
        {
            upd(1, 1, n, i, i);
        }
    }
    cout << get(tr[1]) << '\n';
    while (q--)
    {
        ll p, x;
        cin >> p >> x;
        if (p > 1)
        {
            if (a[p - 1] > x)
            {
                upd(1, 1, n, p - 1, p - 1);
            }
            else
            {
                upd(1, 1, n, p - 1, 0);
            }
        }
        if (p < n)
        {
            if (x > a[p + 1])
            {
                upd(1, 1, n, p, p);
            }
            else
            {
                upd(1, 1, n, p, 0);
            }
        }
        a[p] = x;
        // cout << tr[1] << '\n';
        cout << get(tr[1]) << '\n';
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