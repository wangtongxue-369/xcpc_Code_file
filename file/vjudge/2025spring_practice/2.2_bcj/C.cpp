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
ll h, r;
ll find(ll x)
{
    if (fa[x] != x)
    {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}
struct node
{
    ll x, y, z;
} a[MAXN];
void unio(ll s1, ll s2)
{
    ll t1 = find(s1), t2 = find(s2);
    if (t1 != t2)
    {
        fa[t1] = t2;
    }
}
bool check(ll i, ll j)
{
    if (4 * r * r >= (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].z - a[j].z) * (a[i].z - a[j].z))
    {
        return 1;
    }
    return 0;
}
void solve()
{

    cin >> n >> h >> r;
    vector<ll> bo, to;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
        if (a[i].z - r <= 0)
        {
            bo.push_back(i);
        }
        if (a[i].z + r >= h)
        {
            to.push_back(i);
        }
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
    for (int i = 0; i < bo.size(); i++)
    {
        for (int j = 0; j < to.size(); j++)
        {
            // cout << bo[i] << ' ' << to[j] << '\n';
            if (find(bo[i]) == find(to[j]))
            {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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