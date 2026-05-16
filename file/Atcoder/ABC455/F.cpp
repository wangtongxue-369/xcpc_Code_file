#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> results;

void dfs(vector<ll> a, ll cost)
{
    int n = a.size();

    if (n == 1)
    {
        results.push_back(cost);
        return;
    }

    // 枚举任意两个黏液合并
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            vector<ll> b;

            for (int k = 0; k < n; k++)
            {
                if (k != i && k != j)
                {
                    b.push_back(a[k]);
                }
            }

            ll x = a[i], y = a[j];
            b.push_back(x + y);

            dfs(b, cost + x * y);
        }
    }
}

int main()
{
    vector<ll> a = {2, 3, 5, 7, 10, 4, 6};

    results.clear();
    dfs(a, 0);
    cout << results.size() << '\n';
    cout << "所有可能总花费数量: " << results.size() << '\n';

    for (ll x : results)
    {
        cout << x << '\n';
    }

    ll sum = 0, sq = 0;
    for (ll x : a)
    {
        sum += x;
        sq += x * x;
    }

    ll formula = (sum * sum - sq) / 2;

    cout << "公式计算结果: " << formula << '\n';

    return 0;
}