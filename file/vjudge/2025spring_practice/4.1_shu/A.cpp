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
vector<vector<ll>> ve(MAXN + 10);
ll vis[MAXN + 10];
ll dis[MAXN + 10];
void solve()
{
    ll d;
    cin >> n >> d;
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    queue<PII> q;
    q.push({0, 1});
    vis[1] = 1;
    while (!q.empty())
    {
        auto [s, i] = q.front();
        q.pop();
        dis[i] = s;
        for (auto it : ve[i])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            q.push({s + 1, it});
        }
        // vis[i] = 1;
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dis[i] <= d)
        {
            ans++;
        }
    }
    cout << ans - 1 << '\n';
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