/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
struct Matrix
{
    int n, m;
    vector<vector<ll>> a;
    static const ll MOD = 1e9 + 7; // 可选取模，如不需要可去掉

    // 构造函数
    Matrix(int n, int m, bool identity = false) : n(n), m(m)
    {
        a.assign(n, vector<ll>(m, 0));
        if (identity)
        {
            for (int i = 0; i < n && i < m; i++)
                a[i][i] = 1;
        }
    }

    // 矩阵加法
    Matrix operator+(const Matrix &other) const
    {
        assert(n == other.n && m == other.m);
        Matrix res(n, m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                res.a[i][j] = (a[i][j] + other.a[i][j]) % MOD;
            }
        }
        return res;
    }

    // 矩阵乘法
    Matrix operator*(const Matrix &other) const
    {
        assert(m == other.n);
        Matrix res(n, other.m);
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < m; k++)
            {
                if (a[i][k] == 0)
                    continue; // 小优化
                for (int j = 0; j < other.m; j++)
                {
                    res.a[i][j] = (res.a[i][j] + a[i][k] * other.a[k][j]) % MOD;
                }
            }
        }
        return res;
    }

    // 打印函数
    void print() const
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

// 矩阵快速幂
Matrix power(Matrix base, ll exp)
{
    assert(base.n == base.m);         // 必须是方阵
    Matrix res(base.n, base.m, true); // 单位矩阵
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base;
        base = base * base;
        exp >>= 1;
    }
    return res;
}
void solve()
{
    ll x;
    cin >> n >> x;
    Matrix a(n, n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a.a[i][j];
        }
    }
    a = power(a, x);
    a.print();
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}