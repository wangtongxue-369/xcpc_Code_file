#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
#define lson k << 1, l, mid
#define rson k << 1 | 1, mid + 1, r
ll _ = 1, n, m, ans[MAXN], a[MAXN];
ll tree[MAXN << 2];
void build(ll k, ll l, ll r)
{
    if (l == r)
    {
        tree[k] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(lson), build(rson);
    tree[k] = __gcd(tree[k << 1], tree[k << 1 | 1]);
}
ll qry(ll k, ll l, ll r, ll x, ll y)
{
    if (l >= x && r <= y)
    {
        return tree[k];
    }
    ll mid = (l + r) >> 1;
    ll res = 0;
    if (x <= mid && res == 0)
    {
        res = qry(lson, x, y);
    }
    if (y > mid)
    {
        if (res == 0)
        {
            res = qry(rson, x, y);
        }
        else
        {
            res = __gcd(res, qry(rson, x, y));
        }
    }
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        ll l = i, r = n, res;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            res = qry(1, 1, n, i, mid);
            // cout << "!! " << i << ' ' << mid << ' ' << res << '\n';
            if (res >= mid - i + 1)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        // cout << "!!! " << i << ' ' << l << '\n';
        res = qry(1, 1, n, i, l);
        if (res == l - i + 1)
        {
            // cout << "! " << i << ' ' << l << '\n';
            ans[l]++;
            i = l;
        }
        else
        {
            continue;
        }
    }
    ll p = 0;
    for (int i = 1; i <= n; i++)
    {
        p += ans[i];
        cout << p << ' ';
    }
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
