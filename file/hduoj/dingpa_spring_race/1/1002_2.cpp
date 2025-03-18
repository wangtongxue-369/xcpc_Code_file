#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

// 快速幂取模
long long modPow(long long a, long long b, long long mod = MOD)
{
    long long res = 1 % mod;
    a %= mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

// 模逆元（mod为素数）
long long modInv(long long a, long long mod = MOD)
{
    return modPow(a, mod - 2, mod);
}

// 计算 ceil(log2(n))
int ceilLog2(long long n)
{
    int r = 0;
    while ((1LL << r) < n)
        r++;
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long n;
        int k;
        cin >> n >> k;
        // 读入 k+1 个编号，第一个是候选人染染的编号
        long long p0;
        cin >> p0;
        vector<long long> threats(k);
        for (int i = 0; i < k; i++)
        {
            cin >> threats[i];
        }

        // 如果没有其它威胁，答案即为1
        if (k == 0)
        {
            cout << 1 << "\n";
            continue;
        }

        // R 为满赛程轮数：R = ceil(log2(n))
        int R = (n == 1 ? 0 : ceilLog2(n));
        vector<int> F(R + 1, 0);
        for (auto x : threats)
        {
            int rx = -1;
            for (int r = 1; r <= R; r++)
            {
                long long div = (1LL << r);
                // 注意：编号从1开始，所以用 p0-1 和 x-1
                if ((p0 - 1) / div == (x - 1) / div)
                {
                    rx = r;
                    break;
                }
            }
            // 理论上 rx 一定存在，因为 r = R 时，2^R >= n
            if (rx == -1)
                rx = R;
            F[rx]++;
        }

        // 计算最终答案
        long long ans = 1;
        // 对于每轮 r，满组中候选人对决的“对手区间”大小为 2^(r-1)
        for (int r = 1; r <= R; r++)
        {
            long long tot = (1LL << (r - 1));
            // 如果威胁数大于或等于 tot，则候选人必遇威胁
            if (F[r] >= tot)
            {
                ans = 0;
                break;
            }
            // 躲过这一轮的概率 = (tot - F[r]) / tot
            long long num = (tot - F[r]) % MOD;
            long long den = tot % MOD;
            long long factor = num * modInv(den) % MOD;
            ans = ans * factor % MOD;
        }

        cout << ans % MOD << "\n";
    }
    return 0;
}
