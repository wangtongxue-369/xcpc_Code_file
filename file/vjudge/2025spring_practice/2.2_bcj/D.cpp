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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], fa[MAXN];
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
void solve()
{
    cin >> n;
    vector<PII> ve;
    for (int i = 1; i <= n + 100000; i++)
    {
        fa[i] = i;
    }
    ll s1, s2, e;
    map<ll, ll> ma;
    ll p = 0, p1, p2;
    for (int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2 >> e;
        if (ma.contains(s1) == 0)
        {
            p++;
            ma[s1] = p;
            p1 = p;
        }
        else
        {
            p1 = ma[s1];
        }
        if (ma.contains(s2) == 0)
        {
            p++;
            ma[s2] = p;
            p2 = p;
        }
        else
        {
            p2 = ma[s2];
        }
        if (e == 1)
        {
            unio(p1, p2);
        }
        else
        {
            ve.push_back({p1, p2});
        }
    }
    for (auto it : ve)
    {
        if (find(it.first) == find(it.second))
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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