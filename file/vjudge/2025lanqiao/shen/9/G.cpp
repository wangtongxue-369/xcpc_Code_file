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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN);
void solve()
{
    cin >> n >> m;
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    ll a, b;
    cin >> a >> b;
    vector<ll> dist(n + 10, 1e18);
    priority_queue<PII> q;
    q.push({0, a});
    dist[a] = 0;
    while (q.size())
    {
        auto [dis, u] = q.top();
        q.pop();
        dis *= -1;
        if (dist[u] < dis)
        {
            continue;
        }
        for (auto v : ve[u])
        {
            if (dist[v] > dis + 1)
            {
                dist[v] = dis + 1;
                q.push({-dist[v], v});
            }
        }
    }
    if (dist[b] == 1e18)
    {
        cout << "!" << '\n';
        return;
    }
    cout << dist[b] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
