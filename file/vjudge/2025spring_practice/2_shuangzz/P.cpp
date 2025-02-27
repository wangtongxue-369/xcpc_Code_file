#include <bits/stdc++.h>
using namespace std;
bool visited[10][10];
int sum = 0, n, m, sx, sy, fx, fy, t;
int zx[4] = {0, 0, -1, 1};
int zy[4] = {-1, 1, 0, 0};
void mg(int x, int y)
{
    if (x == fx && y == fy)
    {
        sum++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + zx[i];
        int nexty = y + zy[i];
        if (visited[nextx][nexty] == 0)
        {
            visited[nextx][nexty] = 1;
            mg(nextx, nexty);
            visited[nextx][nexty] = 0;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    visited[sx][sy] = 1;
    for (int i = 0; i <= n + 1; i++)
    {
        visited[0][i] = 1;
        visited[m + 1][i] = 1;
    }
    for (int i = 0; i <= m + 1; i++)
    {
        visited[i][0] = 1;
        visited[i][n + 1] = 1;
    }
    for (int i = 1; i <= t; i++)
    {
        int aaa;
        int bbb;
        cin >> aaa >> bbb;
        visited[aaa][bbb] = 1;
    }

    mg(sx, sy);
    cout << sum;
}