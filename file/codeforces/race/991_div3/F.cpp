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
ll _ = 1, n, m, ans = 0, a[MAXN];
struct node
{
    ll l, r;
    ll data;
} tree[MAXN << 2];
vector<ll> ve;
ll ls(ll x)
{
    return x << 1;
}
ll rs(ll x)
{
    return x << 1 | 1;
}
void build(ll p, ll l, ll r)
{
    // cout << "!" << p << '\n';
    tree[p].l = l;
    tree[p].r = r;
    if (tree[p].l == tree[p].r)
    {
        tree[p].data = ve[tree[p].l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    tree[p].data = __gcd(tree[ls(p)].data, tree[rs(p)].data);
}
ll ask(ll p, ll l, ll r)
{
    if (l <= tree[p].l && tree[p].r <= r)
    {
        return tree[p].data;
    }
    ll mid = (tree[p].l + tree[p].r) >> 1;
    ll res = 0;
    if (l <= mid)
    {
        res = ask(ls(p), l, r);
    }
    if (mid < r)
    {
        ll x = ask(rs(p), l, r);
        if (res == 0)
        {
            res = x;
        }
        else
        {
            res = __gcd(res, x);
        }
    }
    return res;
}
void solve()
{
    ll q;
    cin >> n >> q;
    ve.clear();
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ve.emplace_back(0);
    for (int i = 1; i <= n; i++)
    {
        ve.emplace_back(abs(a[i] - a[i - 1]));
    }
    build(1, 1, n);
    // for (int i = 1; i <= (n << 2); i++)
    // {
    //     cout << "node" << i << '\n';
    //     cout << tree[i].data << ' ';
    //     cout << tree[i].l << ' ' << tree[i].r << '\n';
    // }
    // cout << '\n';
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (l == r)
        {
            cout << 0 << ' ';
            continue;
        }
        cout << ask(1, l + 1, r) << ' ';
    }
    cout << '\n';
}
// mod*k1+a,mod*k2+a,mod*k3+a
// mod*(k1-k2)  mod*();
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
