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
ll _ = 1, n, m, ans = 0, a[MAXN], fa[MAXN], siz[MAXN];
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
        siz[ty] += siz[tx];
    }
}
void solve()
{
    cin >> n;
    vector<set<ll>> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        siz[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ve[i].insert(a[i]);
        ve[a[i]].insert(i);
        unio(i, a[i]);
    }
    set<ll> se1, se2;
    for (int i = 1; i <= n; i++)
    {
        se1.insert(find(i));
        if (ve[i].size() == 1)
        {
            se2.insert(find(i));
        }
    }
    ll res = 0, cnt = 0;
    res = se1.size(), cnt = se2.size();
    // vector<ll> fg(n + 10);
    // for (int i = 1; i <= n; i++)
    // {
    //     fg[find(i)] |= (ve[i].size() == 1);
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (find(i) == i) // gen
    //     {
    //         res++;
    //         cnt += fg[i];
    //     }
    // }
    cout << min(res, res - cnt + 1) << ' ' << res << '\n';
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