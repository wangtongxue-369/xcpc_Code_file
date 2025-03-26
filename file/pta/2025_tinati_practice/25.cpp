#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    int rows1, cols1, rows2, cols2;

    // 输入第一个矩阵
    cin >> rows1 >> cols1;
    vector<vector<int>> mat1(rows1, vector<int>(cols1));
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols1; j++)
            cin >> mat1[i][j];

    // 输入第二个矩阵
    cin >> rows2 >> cols2;
    vector<vector<int>> mat2(rows2, vector<int>(cols2));
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols2; j++)
            cin >> mat2[i][j];

    // 检查矩阵是否可乘
    if (cols1 != rows2)
    {
        cout << "Error: " << cols1 << " != " << rows2 << '\n';
        return;
    }

    // 计算结果矩阵
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // 输出结果
    cout << rows1 << ' ' << cols2 << '\n';
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            cout << result[i][j];
            if (j != cols2 - 1)
            {
                cout << ' ';
            }
        }
        if (i != rows1 - 1)
        {
            cout << endl;
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
