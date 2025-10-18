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
const ll N = 50050;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN],
   t[N << 2], x, y, w, lazy[N << 2];
void build(int rt, int l, int r)
{
    if (l == r)
    {
        t[rt] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
void updata(int rt, int l, int r, int w)
{
    t[rt] += (r - l + 1) * w;
    lazy[rt] += w;
}
void pushdown(int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    updata(rt << 1, l, mid, lazy[rt]);
    updata(rt << 1 | 1, mid + 1, r, lazy[rt]);
    lazy[rt] = 0;
}
void update_point(int rt, int l, int r, int pos, int v)
{
    if (l == r)
    {
        t[rt] += v;
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        update_point(rt << 1, l, mid, pos, v);
    else
        update_point(rt << 1 | 1, mid + 1, r, pos, v);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}

void add(int rt, int l, int r)
{
    if (x <= l && r <= y)
    {
        updata(rt, l, r, w);
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
        add(rt << 1, l, mid);
    if (y > mid)
        add(rt << 1 | 1, mid + 1, r);
    t[rt] = t[rt << 1] + t[rt << 1 | 1];
}
int sum(int rt, int l, int r)
{
    if (x <= l && r <= y)
        return t[rt];
    int mid = (l + r) >> 1, ans = 0;
    pushdown(rt, l, r);
    if (x <= mid)
        ans += sum(rt << 1, l, mid);
    if (y > mid)
        ans += sum(rt << 1 | 1, mid + 1, r);
    return ans;
}
void solve()
{
    cin >> n;
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    ll l, r, v, i;
    while (1)
    {
        string s;
        cin >> s;
        if (s == "End")
        {
            return;
        }
        if (s == "Query")
        {
            cin >> l >> r;
            x = l, y = r;
            cout << sum(1, 1, n) << '\n';
        }
        else if (s == "Add")
        {
            cin >> i >> v;
            update_point(1, 1, n, i, v);
            // updata(1, i, i, v);
        }
        else
        {
            cin >> i >> v;
            update_point(1, 1, n, i, -v);
            // updata(1, i, i, -v);
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    ll p = 1;
    while (_--)
    {
        cout << "Case " << p << ":\n";
        p++;
        solve();
    }
    return 0;
}