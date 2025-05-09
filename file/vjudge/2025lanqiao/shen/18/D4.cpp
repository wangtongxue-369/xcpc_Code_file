#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 20201114;

int k, p;
ll L;

vector<int> dp0, dp1;

struct Matrix
{
    int n;
    vector<vector<int>> a;
    Matrix(int _n) : n(_n), a(n, vector<int>(n)) {}
    Matrix operator*(const Matrix &b) const
    {
        Matrix res(n);
        for (int i = 0; i < n; ++i)
            for (int k = 0; k < n; ++k)
                if (a[i][k])
                    for (int j = 0; j < n; ++j)
                        res.a[i][j] = (res.a[i][j] + (ll)a[i][k] * b.a[k][j]) % MOD;
        return res;
    }
};

Matrix power(Matrix a, ll b)
{
    Matrix res(a.n);
    for (int i = 0; i < a.n; ++i)
        res.a[i][i] = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
    cin >> k >> p >> L;

    int max_k = k;
    dp0.resize(max_k + 1);
    dp1.resize(max_k + 1);
    fill(dp0.begin(), dp0.end(), 0);
    fill(dp1.begin(), dp1.end(), 0);

    for (int i = 1; i <= max_k; ++i)
    {
        // 处理dp0[i]
        if (i <= k && i < p)
            dp0[i] = 1;
        for (int j = 1; j < p; ++j)
        {
            if (i - j < 0)
                continue;
            dp0[i] = (dp0[i] + dp0[i - j] + dp1[i - j]) % MOD;
        }
        // 处理dp1[i]
        if (i <= k && i >= p)
            dp1[i] = 1;
        for (int j = p; j <= k; ++j)
        {
            if (i - j < 0)
                continue;
            dp1[i] = (dp1[i] + dp0[i - j]) % MOD;
        }
    }

    if (L <= max_k)
    {
        cout << (dp0[L] + dp1[L]) % MOD << endl;
        return 0;
    }

    // 构建矩阵，考虑递推式中的依赖
    int m = p - 1 + (k - p + 1) + (p - 1);
    m = max(m, k);
    int size = 2 * (p - 1) + (k - p + 1);
    size = max(size, k);
    size = k * 2;
    m = k * 2;

    vector<int> initial;
    for (int i = max_k - m + 1; i <= max_k; ++i)
    {
        if (i < 0)
        {
            initial.push_back(0);
            initial.push_back(0);
        }
        else
        {
            initial.push_back(dp0[i]);
            initial.push_back(dp1[i]);
        }
    }
    while (initial.size() < m)
        initial.push_back(0);

    Matrix mat(m);
    for (int i = 0; i < m - 2; i += 2)
    {
        mat.a[i + 2][i] = 1;
        mat.a[i + 3][i + 1] = 1;
    }

    int offset = m - 2 * (p - 1) - (k - p + 1);
    for (int i = 0; i < p - 1; ++i)
    {
        mat.a[0][2 * i] = 1;
        mat.a[0][2 * i + 1] = 1;
    }

    for (int i = p - 1; i < k; ++i)
    {
        mat.a[1][2 * (i - (p - 1))] = 1;
    }

    mat.a[0][0] = 0;
    mat.a[0][1] = 0;
    for (int j = 1; j < p; ++j)
    {
        int pos = 2 * (j - 1);
        if (pos >= m)
            break;
        mat.a[0][pos] = 1;
        mat.a[0][pos + 1] = 1;
    }

    int start = 2 * (p - 1);
    for (int j = p; j <= k; ++j)
    {
        int pos = start + (j - p);
        if (pos >= m)
            break;
        mat.a[1][pos] = 1;
    }

    for (int i = 2; i < m; ++i)
    {
        if (i % 2 == 0 && i / 2 - 1 >= 0)
        {
            mat.a[i][i - 2] = 1;
        }
        else if (i % 2 == 1 && (i - 1) / 2 - 1 >= 0)
        {
            mat.a[i][i - 2] = 1;
        }
    }

    Matrix trans = power(mat, L - max_k);

    int result = 0;
    for (int i = 0; i < m; ++i)
    {
        result = (result + (ll)initial[i] * trans.a[0][i] + (ll)initial[i] * trans.a[1][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}