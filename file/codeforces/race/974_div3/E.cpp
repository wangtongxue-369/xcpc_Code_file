#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, h, ans = 0;
vector<vector<PII>> ve(MAXN + 10);
map<ll, ll> ma;
vector<ll> dijstra(ll s)
{
    vector<ll> dist(n * 2 + 10, 1e18);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.emplace(0, 2 * s - 1);
    while (!q.empty())
    {
        auto [d, U] = q.top();
        q.pop();
        if (dist[U] != 1e18)
        {
            continue;
        }
        dist[U] = d;
        ll u = ceil(1.0 * U / 2);
        ll t = U % 2;
        if (t == 1 && ma.count(u) == 1)
        {
            q.emplace(d, u * 2);
        }
        for (auto it : ve[u])
        {
            q.emplace(d + ((t == 0) ? it.second / 2 : it.second), it.first * 2 - t);
        }
    }
    vector<ll> res(n + 10, 1e18);
    for (int i = 1; i <= n; i++)
    {
        res[i] = min(dist[i * 2 - 1], dist[i * 2]);
    }
    return res;
}
void solve()
{
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++)
    {
        ve[i].clear();
    }
    ma.clear();
    ll x;
    for (int i = 1; i <= h; i++)
    {
        cin >> x;
        ma[x]++;
    }
    ll u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
    auto ln = dijstra(1);
    auto rn = dijstra(n);
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, max(ln[i], rn[i]));
    }
    if (ans == 1e18)
    {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
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
