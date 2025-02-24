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
ll _ = 1, n, m, ans = 0;
bool ma[510][510];
bool vis[510];
ll s1[510], s2[510];
ll len1, len2;
void dfs(ll i)
{
    s1[len1++] = i;
    for (int j = 1; j <= n; j++)
    {
        if (j == i || vis[j] == 1)
        {
            continue;
        }
        if (ma[i][j] == 1)
        {
            vis[j] = 1;
            dfs(j);
        }
    }
}
void bfs()
{
    queue<int> q;
    memset(vis, 0, sizeof(vis));
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        ll i = q.front();
        q.pop();
        s2[len2++] = i;
        for (int j = 1; j <= n; j++)
        {
            if (j == i || vis[j] == 1)
            {
                continue;
            }
            if (ma[i][j] == 1)
            {
                vis[j] = 1;
                q.push(j);
            }
        }
    }
}
void solve()
{
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ma[u][v] = 1;
        ma[v][u] = 1;
    }
    vis[1] = 1;
    dfs(1);
    cout << "dfs:";
    for (int i = 0; i < len1; i++)
    {
        cout << s1[i] << ' ';
    }
    cout << '\n';
    bfs();
    cout << "bfs:";
    for (int i = 0; i < len2; i++)
    {
        cout << s2[i] << ' ';
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
