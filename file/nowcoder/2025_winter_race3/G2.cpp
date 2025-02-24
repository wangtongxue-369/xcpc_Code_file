#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long sum_of_mods(long long n, int k)
{
    vector<long long> mods;

    // 计算 n % i 对于 i 从 1 到 sqrt(n)
    for (long long i = 1; i <= sqrt(n); ++i)
    {
        mods.push_back(n % i);
    }

    // 计算 n % i 对于 i 大于 sqrt(n)
    for (long long i = 1; i <= sqrt(n); ++i)
    {
        // 计算 n / i 得到对应的余数
        long long val = n / i;
        // 计算区间 [n / (i + 1), n / i] 内所有的 i 的余数是 val
        for (long long j = n / (i + 1) + 1; j <= n / i; ++j)
        {
            mods.push_back(val);
        }
    }

    // 排序并取前 k 项
    sort(mods.rbegin(), mods.rend()); // 从大到小排序
    long long result = 0;
    for (int i = 0; i < k; ++i)
    {
        result += mods[i];
    }

    return result;
}

int main()
{
    long long n;
    int k;
    cin >> n >> k;

    cout << sum_of_mods(n, k) << endl;

    return 0;
}
