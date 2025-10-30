/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], fa[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(ll x, ll y)
{
    ll tx = find(x);
    ll ty = find(y);
    if (tx != ty)
    {
        fa[tx] = ty;
    }
}
struct node
{
    ll xa, ya, xb, yb;
};
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    vector<node> a(n + 10);
    function<bool(ll i, ll j)> check = [&](ll i, ll j)
    {
        if ((a[i].xa == a[j].xa && a[i].ya == a[j].ya) || (a[i].xa == a[j].xb && a[i].ya == a[j].yb) ||
            (a[i].xb == a[j].xa && a[i].yb == a[j].ya) || (a[i].xb == a[j].xb && a[i].yb == a[j].yb))
        {
            return 1;
        }
        ld K1 = 1.0 * (a[i].ya - a[i].yb) / (a[i].xa - a[i].xb);
        ld C1 = a[i].ya - K1 * a[i].xa;
        ld K2 = 1.0 * (a[j].ya - a[j].yb) / (a[j].xa - a[j].xb);
        ld C2 = 1.0 * a[j].ya - K2 * a[j].xa;
        ld x = (C2 - C1) / (K1 - K2);
        ld y = K1 * x + C1;
        if (min(a[i].xa, a[i].xb) <= x && x <= max(a[i].xa, a[i].xb) &&
            min(a[i].ya, a[i].yb) <= y && y <= max(a[i].ya, a[i].yb) &&
            min(a[j].xa, a[j].xb) <= x && x <= max(a[j].xa, a[j].xb) &&
            min(a[j].ya, a[j].yb) <= y && y <= max(a[j].ya, a[j].yb))
        {
            return 1;
        }
        return 0;
    };

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].xa >> a[i].ya >> a[i].xb >> a[i].yb;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (check(i, j))
            {
                unio(i, j);
            }
        }
    }
    ll u, v;
    while (1)
    {
        cin >> u >> v;
        if (u == 0 && v == 0)
        {
            break;
        }
        if (find(u) == find(v))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
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