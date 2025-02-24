#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 10007;
const ll MAXN = 500005;
const ll N = 100050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
struct node
{
    ll l, r;
    ll add;
    ll rep;
    ll mul;
    ll p[4];
} tree[N << 3 + 5];
void pushdown(ll p)
{
    if (tree[p].rep > 0)
    {
        tree[p * 2].rep = tree[p * 2 + 1].rep = tree[p].rep;
        tree[p * 2].mul = tree[p * 2 + 1].mul = 0;
        tree[p * 2].add = tree[p * 2].add = tree[p].rep;

        ll c = tree[p].rep;
        ll d = (tree[p * 2].r - tree[p * 2].l + 1);

        tree[p * 2].p[3] = c * c % mod * c % mod * d % mod;
        tree[p * 2].p[2] = c * c % mod * d % mod;
        tree[p * 2].p[1] = c * d % mod;

        d = (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);

        tree[p * 2 + 1].p[3] = c * c % mod * c % mod * d % mod;
        tree[p * 2 + 1].p[2] = c * c % mod * d % mod;
        tree[p * 2 + 1].p[1] = c * d % mod;
    }
    if (tree[p].mul != 1)
    {
        tree[p * 2].add = tree[p * 2].add * tree[p].mul % mod;
        tree[p * 2 + 1].add = tree[p * 2 + 1].add * tree[p].mul % mod;

        tree[p * 2].mul = tree[p * 2].mul * tree[p].mul % mod;
        tree[p * 2 + 1].mul = tree[p * 2 + 1].mul * tree[p].mul % mod;

        tree[p * 2].p[3] = tree[p * 2].p[3] * tree[p].mul % mod * tree[p].mul % mod * tree[p].mul % mod;
        tree[p * 2].p[2] = tree[p * 2].p[2] * tree[p].mul % mod * tree[p].mul % mod;
        tree[p * 2].p[1] = tree[p * 2].p[1] * tree[p].mul % mod;

        tree[p * 2 + 1].p[3] = tree[p * 2 + 1].p[3] * tree[p].mul % mod * tree[p].mul % mod * tree[p].mul % mod;
        tree[p * 2 + 1].p[2] = tree[p * 2 + 1].p[2] * tree[p].mul % mod * tree[p].mul % mod;
        tree[p * 2 + 1].p[1] = tree[p * 2 + 1].p[1] * tree[p].mul % mod;

        tree[p].mul = 1;
    }
    if (tree[p].add != 0)
    {

        tree[p * 2].add = (tree[p * 2].add + tree[p].add) % mod;
        tree[p * 2 + 1].add = (tree[p * 2 + 1].add + tree[p].add) % mod;

        tree[p * 2].p[3] = (tree[p * 2].p[3] + 3 * tree[p].add * tree[p * 2].p[2] % mod + 3 * tree[p].add * tree[p].add % mod * tree[p * 2].p[1] % mod + tree[p].add * tree[p].add * tree[p].add % mod * (tree[p * 2].r - tree[p * 2].l + 1) % mod) % mod;
        tree[p * 2].p[2] = (tree[p * 2].p[2] + 2 * tree[p].add * tree[p * 2].p[1] + tree[p].add * tree[p].add % mod * (tree[p * 2].r - tree[p * 2].l + 1) % mod) % mod;
        tree[p * 2].p[1] = (tree[p * 2].p[1] + tree[p].add * (tree[p * 2].r - tree[p * 2].l + 1) % mod) % mod;

        tree[p * 2 + 1].p[3] = (tree[p * 2 + 1].p[3] + 3 * tree[p].add * tree[p * 2 + 1].p[2] % mod + 3 * tree[p].add * tree[p].add % mod * tree[p * 2 + 1].p[1] % mod + tree[p].add * tree[p].add * tree[p].add % mod * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1) % mod) % mod;
        tree[p * 2 + 1].p[2] = (tree[p * 2 + 1].p[2] + 2 * tree[p].add * tree[p * 2 + 1].p[1] + tree[p].add * tree[p].add % mod * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1) % mod) % mod;
        tree[p * 2 + 1].p[1] = (tree[p * 2 + 1].p[1] + tree[p].add * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1) % mod) % mod;

        tree[p].add = 0;
    }
}
void change(ll p, ll l, ll r, ll c, ll op)
{
    if (l <= tree[p].l && tree[p].r <= r)
    {
        ll d = (tree[p].r - tree[p].l + 1) % mod;
        if (op == 1)
        {
            tree[p].add = (tree[p].add + c) % mod;

            tree[p].p[3] = (tree[p].p[3] + 3 * c * tree[p].p[2] % mod + 3 * c * c % mod * tree[p].p[1] % mod + c * c * c % mod * d % mod) % mod;
            tree[p].p[2] = (tree[p].p[2] + 2 * c % mod * tree[p].p[1] % mod + c * c % mod * d % mod) % mod;
            tree[p].p[1] = (tree[p].p[1] + c * d % mod) % mod;
            return;
        }
        else if (op == 2)
        {
            tree[p].add = (tree[p].add * c) % mod;
            tree[p].mul = (tree[p].mul * c) % mod;
            tree[p].p[3] = tree[p].p[3] * c % mod * c % mod * c % mod;
            tree[p].p[2] - tree[p].p[2] * c % mod *c % mod;
            tree[p].p[1] = tree[p].p[1] * c % mod;
            return;
        }
        else if (op == 3)
        {
            tree[p].add = 0;
            tree[p].mul = 1;
            tree[p].rep = c;
            tree[p].p[3] = c * c % mod * c % mod * d % mod;
            tree[p].p[2] = c * c % mod * d % mod;
            tree[p].p[1] = c % mod * d % mod;
            return;
        }
        // return ;
    }
    pushdown(p);
    ll mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
    {
        change(p * 2, l, r, c, op);
    }
    if (mid < r)
    {
        change(p * 2 + 1, l, r, c, op);
    }
    tree[p].p[3] = (tree[p * 2].p[3] + tree[p * 2 + 1].p[3]) % mod;
    tree[p].p[2] = (tree[p * 2].p[2] + tree[p * 2 + 1].p[2]) % mod;
    tree[p].p[1] = (tree[p * 2].p[1] + tree[p * 2 + 1].p[1]) % mod;
}
ll ask(ll p, ll l, ll r, ll op)
{
    if (l <= tree[p].l && tree[p].r <= r)
    {
        return tree[p].p[op] % mod;
    }
    ll res = 0;
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
    {
        res = (res + ask(p * 2, l, r, op)) % mod;
    }
    if (mid < r)
    {
        res = (res + ask(p * 2 + 1, l, r, op)) % mod;
    }
    tree[p].p[3] = (tree[p * 2].p[3] + tree[p * 2 + 1].p[3]) % mod;
    tree[p].p[2] = (tree[p * 2].p[2] + tree[p * 2 + 1].p[3]) % mod;
    tree[p].p[1] = (tree[p * 2].p[1] + tree[p * 2 + 1].p[1]) % mod;
    return res % mod;
}

void build(ll p, ll l, ll r)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].mul = 1;
    tree[p].p[1] = tree[p].p[2] = tree[p].p[3] = 0;
    tree[p].rep = 0;
    tree[p].add = 0;
    ll mid = (l + r) >> 1;
    if (l == r)
    {
        return;
    }
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
}
void solve()
{
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            return;
        }
        // memset(tree, 0, sizeof(tree));
        build(1, 1, n);
        ll op, l, r, c;
        while (m--)
        {
            cin >> op >> l >> r >> c;
            if (op <= 3)
            {
                change(1, l, r, c, op);
            }
            else
            {
                cout << ask(1, l, r, c) % mod << '\n';
            }
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
