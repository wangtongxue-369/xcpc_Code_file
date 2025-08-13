#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> f[i];
    }

    vector<vector<int>> A(n, vector<int>(n, 0));
    vector<vector<bool>> used(n, vector<bool>(n, false));

    // 从大到小放置x，确保行列mex约束
    for (int x = n - 1; x >= 1; --x)
    {
        vector<int> R; // 需要包含x的行：f[i] > x
        for (int i = 0; i < n; ++i)
        {
            if (f[i] > x)
            {
                R.push_back(i);
            }
        }
        vector<int> C; // 需要包含x的列：f[j] > x
        for (int j = 0; j < n; ++j)
        {
            if (f[j] > x)
            {
                C.push_back(j);
            }
        }

        // 排序优化匹配：行按f[i]升序，列按索引升序
        sort(R.begin(), R.end(), [&](int i, int j)
             { return f[i] < f[j]; });
        sort(C.begin(), C.end());

        vector<bool> col_used(n, false); // 标记列是否已使用当前x
        for (int i : R)
        {
            int found = -1;
            // 寻找未使用的(i,j)位置
            for (int j : C)
            {
                if (!used[i][j] && !col_used[j])
                {
                    found = j;
                    break;
                }
            }
            if (found != -1)
            {
                A[i][found] = x;
                used[i][found] = true;
                col_used[found] = true;
            }
        }
    }

    // 输出矩阵
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}