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
ll _ = 1, n, m, ans = 0, a[2500][2500], fa[MAXN];
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
    vector<array<ll, 3>> ve;
    cin >> n;
    ll w;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        ve.push_back({w, i, n + 1});
        ve.push_back({w, n + 1, i});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            if (i != j)
            {
                ve.push_back({a[i][j], i, j});
            }
        }
    }
    sort(ve.begin(), ve.end());
    for (int i = 1; i <= n + 1; i++)
    {
        fa[i] = i;
    }
    ans = 0;
    for (auto it : ve)
    {
        auto [w, x, y] = it;
        if (find(x) == find(y))
        {
            continue;
        }
        unio(x, y);
        ans += w;
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