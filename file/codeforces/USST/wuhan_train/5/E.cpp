
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long
#define pb push_back
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>

void solve()
{
    int n;
    cin >> n;
    vector<int> e[n + 1];
    for (int i = 1; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    vector<int> d(n + 1);
    int c{0};
    auto dfs = [&](auto &&self, int u, int fa) -> void
    {
        for (int v : e[u])
        {
            if (v == fa)
                continue;
            d[v] = d[u] + 1;
            if (d[v] > d[c])
                c = v;
            self(self, v, u);
        }
    };
    dfs(dfs, 1, 0);
    d[c] = 0, dfs(dfs, c, 0);
    // d[c] => R

    int r, t0;
    cin >> r >> t0;
    vector<int> dis(n + 1, INF);
    queue<int> q;
    q.push(r);
    dis[r] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : e[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    int d_max = *max_element(dis.begin() + 1, dis.end()), d_mx{0};
    vector<int> tmp;
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size() == 1)
        {
            tmp.pb(dis[i]);
        }
    }
    sort(tmp.begin() + 1, tmp.end());
    d_mx = *(tmp.end() - 2);
    // cout << d_max << endl;
    // for (auto d : dis)
    //     cout << d << ' ';
    // cout << endl;
    for (int k = 1; k <= n; k++)
    {
        if (k == 1)
            cout << (d[c] + 1) / 2 << ' ';
        else
        {
            int v = k - 1;
            cout << min((d_max + k - 1) / k, (t0 + v - 1) / v) << " \n"[k == n];
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}