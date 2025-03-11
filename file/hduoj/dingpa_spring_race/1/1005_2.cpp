#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

typedef tuple<long long, int, int, int> State; // (cost, x, y, direction)

const int dx[4] = {0, 1, 0, -1}; // 右、下、左、上
const int dy[4] = {1, 0, -1, 0};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> t(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> t[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> d[i][j];

    vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(4, LLONG_MAX)));
    priority_queue<State, vector<State>, greater<State>> pq;

    // 初始状态，起点向右
    dist[0][0][0] = t[0][0];
    pq.emplace(t[0][0], 0, 0, 0);

    while (!pq.empty())
    {
        auto [cost, x, y, dir] = pq.top();
        pq.pop();

        if (cost > dist[x][y][dir])
            continue;

        // 尝试四个方向
        for (int new_dir = 0; new_dir < 4; new_dir++)
        {
            int nx = x + dx[new_dir], ny = y + dy[new_dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            long long new_cost = cost + t[nx][ny];
            if (new_dir != dir)
                new_cost += d[nx][ny];

            if (new_cost < dist[nx][ny][new_dir])
            {
                dist[nx][ny][new_dir] = new_cost;
                pq.emplace(new_cost, nx, ny, new_dir);
            }
        }
    }

    // 取终点 (n-1, m-1) 的最小值
    cout << dist[n - 1][m - 1][0] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
