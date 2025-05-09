#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 20201114;

int k, p;
ll L;

vector<int> multiply(const vector<int> &a, const vector<int> &b, const vector<int> &m)
{
    int n = a.size(), len = b.size();
    vector<int> res(n + len - 1, 0);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < len; ++j)
            res[i + j] = (res[i + j] + 1LL * a[i] * b[j]) % MOD;
    for (int i = res.size() - 1; i >= m.size() - 1; --i)
    {
        if (res[i] == 0)
            continue;
        for (int j = 0; j < m.size(); ++j)
            res[i - (m.size() - 1) + j] = (res[i - (m.size() - 1) + j] - 1LL * res[i] * m[j] % MOD + MOD) % MOD;
    }
    res.resize(m.size() - 1);
    return res;
}

vector<int> poly_pow(ll power, const vector<int> &poly)
{
    vector<int> res = {1};
    vector<int> base = {0, 1};
    while (power > 0)
    {
        if (power & 1)
            res = multiply(res, base, poly);
        base = multiply(base, base, poly);
        power >>= 1;
    }
    return res;
}

int linear_recurrence(ll n, const vector<int> &a, const vector<int> &init)
{
    int m = a.size();
    if (n < init.size())
        return init[n] % MOD;
    vector<int> poly(m + 1, 0);
    poly[m] = 1;
    for (int i = 0; i < m; ++i)
        poly[m - 1 - i] = (MOD - a[i]) % MOD;
    vector<int> xn = poly_pow(n, poly);
    int res = 0;
    for (int i = 0; i < xn.size(); ++i)
        res = (res + 1LL * xn[i] * init[i]) % MOD;
    return res;
}

int main()
{
    cin >> k >> p >> L;
    if (L == 0)
    {
        cout << 1 % MOD << endl;
        return 0;
    }

    int m = k + p - 1;
    vector<int> f(m, 0), g(m, 0);
    f[0] = 1;
    for (int n = 1; n < m; ++n)
    {
        for (int i = 1; i <= p - 1 && i <= n; ++i)
        {
            f[n] = (f[n] + f[n - i]) % MOD;
            f[n] = (f[n] + g[n - i]) % MOD;
        }
        for (int i = p; i <= k && i <= n; ++i)
            g[n] = (g[n] + f[n - i]) % MOD;
    }

    vector<int> a(m, 0);
    for (int d = 1; d <= m; ++d)
    {
        if (d <= p - 1)
        {
            a[d - 1] = 1;
        }
        else if (d >= p + 1 && d <= k + p - 1)
        {
            int low = max(1, d - k);
            int high = min(p - 1, d - p);
            a[d - 1] = (high >= low) ? (high - low + 1) % MOD : 0;
        }
        else
        {
            a[d - 1] = 0;
        }
    }

    vector<int> init;
    for (int i = 0; i < m; ++i)
        init.push_back(f[i]);

    int fL = linear_recurrence(L, a, init);

    int gL = 0;
    for (int i = p; i <= k; ++i)
    {
        if (L >= i)
            gL = (gL + linear_recurrence(L - i, a, init)) % MOD;
    }

    cout << (fL + gL) % MOD << endl;
    return 0;
}