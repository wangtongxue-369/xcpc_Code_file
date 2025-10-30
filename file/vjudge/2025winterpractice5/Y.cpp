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
    function<ll(PII p1, PII p2, PII p3)> cross = [&](PII p1, PII p2, PII p3)
    {
        return (p2.first - p1.first) * (p3.second - p1.second) -
               (p2.second - p1.second) * (p3.first - p1.first);
    };
    function<bool(PII p1, PII p2, PII q)> onseg = [&](PII p1, PII p2, PII q)
    {
        return min(p1.first, p2.first) <= q.first && q.first <= max(p1.first, p2.first) &&
               min(p1.second, p2.second) <= q.second && q.second <= max(p1.second, p2.second);
    };
    function<bool(ll i, ll j)> check = [&](ll i, ll j)
    {
        if ((a[i].xa == a[j].xa && a[i].ya == a[j].ya) || (a[i].xa == a[j].xb && a[i].ya == a[j].yb) ||
            (a[i].xb == a[j].xa && a[i].yb == a[j].ya) || (a[i].xb == a[j].xb && a[i].yb == a[j].yb))
        {
            return 1;
        }

        PII A = {a[i].xa, a[i].ya}, B = {a[i].xb, a[i].yb};
        PII C = {a[j].xa, a[j].ya}, D = {a[j].xb, a[j].yb};

        ll c1 = cross(A, B, C);
        ll c2 = cross(A, B, D);
        ll c3 = cross(C, D, A);
        ll c4 = cross(C, D, B);

        if ((c1 > 0 && c2 < 0 || c1 < 0 && c2 > 0) && (c3 > 0 && c4 < 0 || c3 < 0 && c4 > 0))
            return 1;
        if (c1 == 0 && onseg(A, B, C))
            return 1;
        if (c2 == 0 && onseg(A, B, D))
            return 1;
        if (c3 == 0 && onseg(C, D, A))
            return 1;
        if (c4 == 0 && onseg(C, D, B))
            return 1;

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
                // cout << i << ' ' << j << '\n';
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