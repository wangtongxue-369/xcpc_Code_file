#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mx1[3] = {1, 0, -1};
int my1[3] = {0, -1, 0};

int mx2[3] = {1, 0, -1};
int my2[3] = {0, 1, 0};
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> mp[i];
    }
    vector<vector<int>> a(n, vector<int>(m, 1));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<array<int, 2>> q;
    q.push({0, m - 1});
    vis[0][m - 1] = 1;
    a[0][m - 1] = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            int nx = x + mx1[i];
            int ny = y + my1[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || mp[nx][ny] == '1')
            {
                continue;
            }
            vis[nx][ny] = 1;
            q.push({nx, ny});
            a[nx][ny] = 0;
        }
    }
    // for(int i=0;i<n;i++){
    // for(int j=0;j<m;j++){
    // cout<<a[i][j]<<" \n"[j==m-1];
    // }
    // }
    vector<vector<int>> viss(n, vector<int>(m, 0));
    queue<array<int, 2>> qq;
    qq.push({0, 0});
    viss[0][0] = 1;
    int fl = 0;
    while (!qq.empty())
    {
        auto [x, y] = qq.front();
        // cout<<x<<" "<<y<<"\n";
        qq.pop();
        for (int i = 0; i < 3; i++)
        {
            int nx = x + mx2[i];
            int ny = y + my2[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || viss[nx][ny] || mp[nx][ny] == '1')
            {
                continue;
            }
            if (a[nx][ny])
            {
                int fll = 0;
                int yr = min(y + k, m - 1);
                for (int j = y; j <= yr; j++)
                {
                    if (mp[x][j] == '1')
                    {
                        fll = 1;
                        break;
                    }
                }
                if (!fll)
                {
                    fl = 1;
                }
            }
            if (fl)
                break;
            viss[nx][ny] = 1;
            qq.push({nx, ny});
        }
        if (fl)
        {
            break;
        }
    }
    if (fl)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}