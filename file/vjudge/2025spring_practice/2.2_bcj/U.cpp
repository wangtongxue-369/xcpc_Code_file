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
ll _ = 1, n, m, ans = 0, fa[MAXN];
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
void unio(ll s1, ll s2)
{
    ll t1 = find(s1), t2 = find(s2);
    if (t1 != t2)
    {
        fa[t1] = t2;
    }
}
struct node
{
    ll x, y, z;
};
bool cmp(node s1, node s2)
{
    return s1.z < s2.z;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    ll x, y, z;
    vector<node> a;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> z;
        a.push_back({x, y, z});
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < m; i++)
    {
        ll tx = find(a[i].x), ty = find(a[i].y);
        if (tx == ty)
        {
            continue;
        }
        ans += a[i].z;
        unio(find(a[i].x), find(a[i].y));
    }
    for (int i = 1; i <= n; i++)
    {
        if (find(1) != find(i))
        {
            cout << "orz\n";
            return;
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