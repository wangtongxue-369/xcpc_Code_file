#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        vector<string> grid(N);
        for (int i = 0; i < N; i++)
        {
            cin >> grid[i];
        }

        vector<vector<bool>> actual_reachable(N, vector<bool>(M, false));
        queue<Point> q_actual;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        actual_reachable[0][M - 1] = true;
        q_actual.push(Point(0, M - 1));
        while (!q_actual.empty())
        {
            Point p = q_actual.front();
            q_actual.pop();
            for (int d = 0; d < 4; d++)
            {
                int nr = p.r + dr[d];
                int nc = p.c + dc[d];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if (grid[nr][nc] == '1')
                    continue;
                if (actual_reachable[nr][nc])
                    continue;
                actual_reachable[nr][nc] = true;
                q_actual.push(Point(nr, nc));
            }
        }

        vector<vector<int>> g_all(N, vector<int>(M, -INF));
        for (int c = M - 1; c >= 0; c--)
        {
            for (int r = 0; r < N; r++)
            {
                if (grid[r][c] == '1')
                {
                    g_all[r][c] = -INF;
                    continue;
                }
                g_all[r][c] = c;
                if (c + 1 < M && grid[r][c + 1] != '1')
                {
                    g_all[r][c] = max(g_all[r][c], g_all[r][c + 1]);
                }
            }
            for (int r0 = 0; r0 < N;)
            {
                if (grid[r0][c] == '1')
                {
                    r0++;
                    continue;
                }
                int r1 = r0;
                while (r1 < N && grid[r1][c] == '0')
                {
                    r1++;
                }
                int max_val = -INF;
                for (int r = r0; r < r1; r++)
                {
                    if (g_all[r][c] > max_val)
                    {
                        max_val = g_all[r][c];
                    }
                }
                for (int r = r0; r < r1; r++)
                {
                    g_all[r][c] = max_val;
                }
                r0 = r1;
            }
        }

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<Point> q_opt;
        q_opt.push(Point(0, 0));
        visited[0][0] = true;
        bool found_dead = false;

        if (!actual_reachable[0][0])
        {
            cout << "Yes\n";
            continue;
        }

        while (!q_opt.empty() && !found_dead)
        {
            Point p = q_opt.front();
            q_opt.pop();
            if (!actual_reachable[p.r][p.c])
            {
                found_dead = true;
                break;
            }
            int moves[3][2] = {{1, 0}, {-1, 0}, {0, 1}};
            for (int d = 0; d < 3; d++)
            {
                int nr = p.r + moves[d][0];
                int nc = p.c + moves[d][1];
                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;
                if (grid[nr][nc] == '1')
                    continue;
                if (visited[nr][nc])
                    continue;
                int vision_end = min(p.c + K, M - 1);
                if (g_all[nr][nc] < vision_end)
                {
                    continue;
                }
                visited[nr][nc] = true;
                q_opt.push(Point(nr, nc));
            }
        }

        if (found_dead)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }

    return 0;
}