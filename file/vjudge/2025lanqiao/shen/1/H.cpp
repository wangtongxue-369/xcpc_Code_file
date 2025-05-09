#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 100003;
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans[MAXN], f[MAXN], dis[MAXN];
vector<vector<ll>> ve(MAXN + 10);
// vector<ll> dis(MAXN + 10, 1e10);
void solve()
{
    cin >> n >> m;
    ll x, y;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = 1e9;
    }

    dis[1] = 0;
    ans[1] = 1;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    while (q.size())
    {
        auto [dist, u] = q.top();
        q.pop();
        // cout << u << ' ' << dis[u] << ' ' << dist << '\n';
        if (f[u])
        {
            continue;
        }
        f[u] = 1;
        for (auto v : ve[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                ans[v] = ans[u];
                q.push({dis[v], v});
            }
            else if (dis[v] == dis[u] + 1)
            {
                ans[v] += ans[u];
                ans[v] %= mod;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dis[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    cout << '\n';
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
