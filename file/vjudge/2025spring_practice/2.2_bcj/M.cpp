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
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
    {
        fa[i] = i;
    }
    vector<array<ll, 3>> ve;
    ll s1, s2, x;
    for (int i = 1; i <= m; i++)
    {
        cin >> s1 >> s2 >> x;
        ve.push_back({x, s1, s2});
    }
    sort(ve.begin(), ve.end(), greater<>());
    for (auto it : ve)
    {
        ll x = it[1], y = it[2];
        unio(x, y + n);
        unio(y, x + n);
        if (find(x) == find(x + n) || find(y) == find(y + n))
        {
            cout << it[0] << '\n';
            return;
        }
    }
    cout << 0 << '\n';
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