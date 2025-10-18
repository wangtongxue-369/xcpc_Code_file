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
ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
const ll N = 100050;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r
ll seg[N << 2], mul[N << 2], add[N << 2];

void pushdown(ll k, ll l, ll r)
{
    ll mid = (l + r) >> 1, lt = k << 1, rt = k << 1 | 1;

    seg[lt] = (seg[lt] * mul[k] % mod + (mid - l + 1) * add[k] % mod) % mod;
    mul[lt] = mul[lt] * mul[k] % mod;
    add[lt] = (add[lt] * mul[k] % mod + add[k]) % mod;

    seg[rt] = (seg[rt] * mul[k] % mod + (r - mid) * add[k] % mod) % mod;
    mul[rt] = mul[rt] * mul[k] % mod;
    add[rt] = (add[rt] * mul[k] % mod + add[k]) % mod;

    mul[k] = 1;
    add[k] = 0;
}

void build(ll k, ll l, ll r)
{
    mul[k] = 1;
    add[k] = 0;
    if (l == r)
    {
        seg[k] = a[l] % mod;
        return;
    }
    ll mid = (l + r) >> 1;
    build(lson), build(rson);
    seg[k] = (seg[k << 1] + seg[k << 1 | 1]) % mod;
}

// 区间乘
void upd(ll k, ll l, ll r, ll x, ll y, ll z)
{
    if (l >= x && r <= y)
    {
        seg[k] = seg[k] * z % mod;
        mul[k] = mul[k] * z % mod;
        add[k] = add[k] * z % mod;
        return;
    }
    if (mul[k] != 1 || add[k] != 0)
        pushdown(k, l, r);
    ll mid = (l + r) >> 1;
    if (x <= mid)
        upd(lson, x, y, z);
    if (y > mid)
        upd(rson, x, y, z);
    seg[k] = (seg[k << 1] + seg[k << 1 | 1]) % mod;
}

// 区间加
void addr(ll k, ll l, ll r, ll x, ll y, ll z)
{
    if (l >= x && r <= y)
    {
        seg[k] = (seg[k] + (r - l + 1) * z % mod) % mod;
        add[k] = (add[k] + z) % mod;
        return;
    }
    if (mul[k] != 1 || add[k] != 0)
        pushdown(k, l, r);
    ll mid = (l + r) >> 1;
    if (x <= mid)
        addr(lson, x, y, z);
    if (y > mid)
        addr(rson, x, y, z);
    seg[k] = (seg[k << 1] + seg[k << 1 | 1]) % mod;
}

ll qry(ll k, ll l, ll r, ll x, ll y)
{
    if (l >= x && r <= y)
        return seg[k] % mod;
    if (mul[k] != 1 || add[k] != 0)
        pushdown(k, l, r);
    ll mid = (l + r) >> 1, res = 0;
    if (x <= mid)
        res += qry(lson, x, y);
    if (y > mid)
        res += qry(rson, x, y);
    return res % mod;
}
void solve()
{
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    ll op, x, y, k;
    while (m--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            upd(1, 1, n, x, y, k);
        }
        else if (op == 2)
        {
            cin >> x >> y >> k;
            addr(1, 1, n, x, y, k);
        }
        else if (op == 3)
        {
            cin >> x >> y;
            cout << qry(1, 1, n, x, y) << '\n';
        }
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