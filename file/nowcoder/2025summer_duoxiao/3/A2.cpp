#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> b(n + 10, vector<int>(n + 10, 0));
    for (int i = 0; i < n; i++)
    {
        b[0][i] = a[i] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        int x = b[j][i];
        if (x == 0)
        {
            continue;
        }
        while (1)
        {
            if (b[j][i] == a[i] || b[j][i] == a[j])
            {
                b[j + 1][i] = b[j][i];
                b[j][i] = 0;
                j++;
            }
            else
            {
                x--;
                b[j + 1][i] = x;
                j++;
            }
            if (x == 0)
            {
                break;
            }
            if (j == n)
            {
                x--;
                if (x == 0)
                {
                    break;
                }
                int z = j;
                while (z--)
                {
                    if (b[z][i])
                    {
                        continue;
                    }
                    if (a[z] != x && a[i] != x)
                    {
                        b[z][i] = x;
                        x--;
                    }
                    if (x == 0)
                    {
                        break;
                    }
                }
            }
            if (x == 0)
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[j][i] && b[i][j] && b[j][i] != b[i][j])
            {
                int x = i - 1;
                while (x--)
                {
                    if (b[x][j])
                    {
                        continue;
                    }
                    if (a[x] != b[i][j] && a[j] != b[i][j])
                    {
                        b[x][j] = b[i][j];
                        b[i][j] = b[j][i];
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j])
            {
                b[j][i] = b[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << b[i][j] << " \n"[j == n - 1];
        }
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