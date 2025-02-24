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
ll _ = 1, n, m, ans = 0;          // a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN + 10); // 邻接表
vector<ll> max_val(MAXN, -1);     // 每个点所在环的最大权值
bool visited[MAXN];               // 访问标记
ll parent[MAXN];                  // 父节点
ll a[MAXN];                       // 节点权值
void dfs(ll u, ll &max_a)
{
    visited[u] = true;
    for (ll v : ve[u])
    {
        if (!visited[v])
        {
            parent[v] = u;
            dfs(v, max_a);
        }
        else if (v != parent[u])
        { // 发现环
            ll current = u;
            ll ring_max = a[u];
            while (current != v)
            {
                ring_max = max(ring_max, a[current]);
                current = parent[current];
            }
            ring_max = max(ring_max, a[v]);
            // 更新环中所有节点的最大权值
            current = u;
            while (current != v)
            {
                max_val[current] = ring_max;
                current = parent[current];
            }
            max_val[v] = ring_max;
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> hzmin(n + 10);
    vector<ll> qzmax(n + 10);
    vector<ll> ans(n + 10);
    qzmax[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[qzmax[i - 1]])
        {
            qzmax[i] = i;
        }
        else
        {
            qzmax[i] = qzmax[i - 1];
        }
    }
    hzmin[n] = n;
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[hzmin[i + 1]])
        {
            hzmin[i] = i;
        }
        else
        {
            hzmin[i] = hzmin[i + 1];
        }
    }
    // cout << '!' << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << qzmax[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << hzmin[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (i != qzmax[i])
        {
            ve[i].push_back(qzmax[i]);
        }
        if (i != hzmin[i])
        {
            ve[i].push_back(hzmin[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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
