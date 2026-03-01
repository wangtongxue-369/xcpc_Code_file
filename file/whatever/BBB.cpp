#include <bits/stdc++.h>
using namespace std;
int n, m, s, t, tem1;
vector<vector<int>> p(10005), p1(10005);
int vis[100005], vis2[100005], vis3[100005], vis4[100005];
queue<pair<int, int>> q; // 点，步数
void dfs1(int n1)
{
    for (int i = 0; i < p1[n1].size(); i++)
    {
        if (vis4[p1[n1][i]] == 0)
        {
            vis4[p1[n1][i]] = 1;
            dfs1(p1[n1][i]);
        }
    }
}
void bfs()
{
    while (!q.empty())
    {
        pair<int, int> pi = q.front();
        q.pop();
        if (pi.first == t)
        {
            cout << pi.second;
            return;
        }
        for (int i = 0; i < p[pi.first].size(); i++)
        {
            if (vis[p[pi.first][i]] == 0 and vis2[p[pi.first][i]] == 0)
            {

                vis2[p[pi.first][i]] = 1;
                q.push({p[pi.first][i], pi.second + 1});
            }
        }
    }
    cout << -1;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u != v)
        {
            p[u].push_back(v);
            p1[v].push_back(u);
        }
    }
    cin >> s >> t;

    vis4[t] = 1;

    dfs1(t);

    for (int i = 1; i <= n; i++)
    {
        if (vis4[i] == 0)
        {
            for (int j = 0; j < p1[i].size(); j++)
            {
                // cout << p1[i][j] << " ";
                vis[p1[i][j]] = 1;
            }
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (vis[i] == 0)
    //     {
    //         cout << i << ' ';
    //     }
    // }
    // cout << '\n';

    if (vis[s] == 0)
        q.push({s, 0});
    bfs();

    return 0;
}