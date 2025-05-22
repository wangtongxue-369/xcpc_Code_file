#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAXN = 105; // 假设n,m <= 100
int sg[MAXN][MAXN];

int get_sg(int a, int b)
{
    cout << a << ' ' << b << '\n';
    if (sg[a][b] != -1)
        return sg[a][b];
    set<int> s;

    // 从a取出2k个，放k个到b中
    for (int k = 1; 2 * k <= a; ++k)
    {
        s.insert(get_sg(a - 2 * k, b + k));
    }

    // 从b取出2k个，放k个到a中
    for (int k = 1; 2 * k <= b; ++k)
    {
        s.insert(get_sg(a + k, b - 2 * k));
    }

    // mex
    int g = 0;
    while (s.count(g))
        ++g;
    return sg[a][b] = g;
}

int main()
{
    // 初始化
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            sg[i][j] = -1;

    // 打表
    for (int i = 0; i < MAXN; ++i)
        for (int j = 0; j < MAXN; ++j)
            get_sg(i, j);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << sg[i][j] << ' ';
        }
        cout << '\n';
    }

    if (sg[n][m] != 0)
        cout << "Alice" << endl; // 先手必胜
    else
        cout << "Brown" << endl; // 后手必胜
    return 0;
}
