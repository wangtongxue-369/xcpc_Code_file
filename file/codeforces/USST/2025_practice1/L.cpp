#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, w[MAXN], dis[105][MAXN];
vector<vector<ll>> ve(MAXN + 10);
vector<vector<ll>> ladu(200 + 10);
void solve()
{
    ll q;
    cin >> n >> m >> q;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dis[i][j] = 1e18;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        ladu[w[i]].push_back(i);
    }
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    // 找到每个辣度的店距离
    ll p;
    for (int i = 1; i <= 100; i++)
    {
        if (ladu[i].size() == 0)
        {
            continue;
        }
        queue<ll> q;
        for (auto it : ladu[i])
        {
            dis[i][it] = 0;
            q.push(it);
        }
        while (q.size())
        {
            auto x = q.front();
            q.pop();
            for (auto it : ve[x])
            {
                if (dis[i][it] == 1e18)
                {
                    dis[i][it] = dis[i][x] + 1;
                    q.push(it);
                }
            }
        }
    }
    // for (int i = 1; i <= 100; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    for (int i = 2; i <= 100; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = min(dis[i - 1][j], dis[i][j]);
        }
    }
    // for (int i = 1; i <= 100; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << dis[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    ll a;
    for (int i = 1; i <= q; i++)
    {
        cin >> p >> a;
        if (dis[a][p] == 1e18)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << dis[a][p] << '\n';
        }
    }
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
