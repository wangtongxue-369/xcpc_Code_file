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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
vector<vector<ll>> ve(200005 + 10);
vector<ll> vis(200005 + 10);
void dfs(ll i)
{
    for (auto it : ve[i])
    {
        if (vis[it])
        {
            continue;
        }
        vis[it] = 1;
        cout << it << ' ';
        dfs(it);
    }
}
void bfs()
{
    fill(vis.begin(), vis.end(), 0);
    queue<ll> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        ll t = q.front();
        q.pop();
        cout << t << ' ';
        for (auto it : ve[t])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            q.push(it);
        }
    }
}

void solve()
{
    cin >> n >> m;
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(ve[i].begin(), ve[i].end());
    }
    // for (auto it : ve[7])
    // {
    //     cout << it << ' ';
    // }
    // cout << '\n';
    vis[1] = 1;
    cout << 1 << ' ';
    dfs(1);
    cout << '\n';
    bfs();
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