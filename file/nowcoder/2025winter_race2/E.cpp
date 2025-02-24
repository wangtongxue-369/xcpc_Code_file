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
ll _ = 1, n, m, ans = 0, a[MAXN], pra[MAXN];
ll lazy[MAXN << 2], tree[MAXN << 2];
void build(ll k, ll l, ll r)
{
    if (l == r)
    {
        tree[k] = a[l] - pra[l - 1];
        return;
    }
    ll mid = (l + r) >> 1;
    build(k << 1, l, mid);
    build(k << 1 | 1, mid + 1, r);
    tree[k] = max(tree[k << 1], tree[k << 1 | 1]);
}
ll ask(ll k, ll l, ll r, ll x, ll y)
{
    if (l >= x && r <= y)
    {
        return tree[k];
    }
    ll mid = (l + r) >> 1;
    ll res = -1e18;
    if (x <= mid)
    {
        res = max(res, ask(k << 1, l, mid, x, y)); // 查询左子区间
    }
    if (y > mid)
    {
        res = max(res, ask(k << 1 | 1, mid + 1, r, x, y)); // 查询右子区间
    }
    return res;
}
void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pra[i] = pra[i - 1] + a[i];
    }
    build(1, 1, n);
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l + 1 > r)
        {
            cout << 0 << '\n';
            continue;
        }
        ll ma = ask(1, 1, n, l + 1, r);
        // cout << ma << ' ' << -1 * pra[l - 1] << '\n';
        if (ma <= -1 * pra[l - 1])
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << ma + pra[l - 1] << '\n';
        }
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
