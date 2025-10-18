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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll fa[2 * MAXN], k;
ll find(ll x)
{
    if (fa[x] != x)
    {
        return find(fa[x]);
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
    return;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= 3 * n; i++)
    {
        fa[i] = i;
    }
    ll op, x, y;
    while (k--)
    {
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (op == 1)
        {
            if (find(x) == find(n + y) || find(x) == find(y + 2 * n))
            {
                ans++;
            }
            else
            {
                unio(x, y);
                unio(y + n, x + n);
                unio(x + 2 * n, y + 2 * n);
            }
        }
        else
        {
            if (x == y)
            {
                ans++;
                continue;
            }
            if ((find(x) == find(y) || find(x) == find(y + n)))
            {
                ans++;
            }
            else
            {
                unio(x + n, y);
                unio(x + 2 * n, y + n);
                unio(x, y + 2 * n);
            }
        }
    }
    cout << ans << '\n';
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