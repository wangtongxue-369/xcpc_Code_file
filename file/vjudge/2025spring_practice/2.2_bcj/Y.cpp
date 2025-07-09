#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 2005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, fa[MAXN], c[MAXN], k[MAXN];
PII a[MAXN];
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
    ll x, y;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cin >> a[i].first >> a[i].second;
    }
    fa[n + 1] = n + 1;
    vector<array<ll, 3>> ve;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        ve.push_back({c[i], i, n + 1});
        ve.push_back({c[i], n + 1, i});
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                ve.push_back({(k[i] + k[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)), i, j});
                // ve.push_back({(k[i] + k[j]) * (abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second)), j, i});
            }
        }
    }
    ll v = 0, e = 0;
    vector<ll> vv;
    vector<PII> ww;
    sort(ve.begin(), ve.end());
    for (auto it : ve)
    {
        auto [w, x, y] = it;
        if (find(x) == find(y))
        {
            continue;
        }
        unio(x, y);
        ans += w;
        if (y == n + 1 || x == n + 1)
        {
            vv.push_back((y == n + 1 ? x : y));
        }
        else
        {
            ww.push_back({x, y});
        }
    }
    cout << ans << '\n';
    cout << vv.size() << '\n';
    for (auto it : vv)
    {
        cout << it << ' ';
    }
    cout << '\n';
    cout << ww.size() << '\n';
    for (auto it : ww)
    {
        cout << it.first << ' ' << it.second << '\n';
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