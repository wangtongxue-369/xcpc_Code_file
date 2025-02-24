#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1);
        vector<bool> visited(n + 1, false);
        vector<int> in_degree(n + 1, 0);

        // 构建图
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            in_degree[u]++;
            in_degree[v]++;
        }

        int new_edges_needed = 0;

        // 对每个连通分量进行拓扑排序
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
            {
                // 使用BFS或DFS找连通分量
                queue<int> q;
                visited[i] = true;
                q.push(i);

                while (!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : graph[node])
                    {
                        if (!visited[neighbor])
                        {
                            visited[neighbor] = true;
                            q.push(neighbor);
                        }
                    }
                }

                new_edges_needed++;
            }
        }

        cout << new_edges_needed - 1 << endl;
    }

    return 0;
}
