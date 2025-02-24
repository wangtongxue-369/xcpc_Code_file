// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define INF 0x3f3f3f3f
// #define PII pair<ll, ll>
// const ll mod = 1e9 + 7;
// const ll MAXN = 500005;
// const ll base1 = 131;
// const ll base2 = 127;
// ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
// ll suma[MAXN],sumb[MAXN],sumc[MAXN],sumf[MAXN];
// void solve()
// {
//     ll k;
//     string s;
//     cin >> n >> k;
//     cin >> s;s=' '+s;
//     for (int i=1;i<=n;i++)
//     {
//         suma[i]=suma[i-1]+(s[i]=='A'?1:0);
//         sumb[i]=sumb[i-1]+(s[i]=='B'?1:0);
//         sumc[i]=sumc[i-1]+(s[i]=='C'?1:0);
//         sumf[i]=sumf[i-1]+(s[i]=='?'?1:0);
//     }
//     for (int len=2;len<=50;len++)
//     {
//         for (int i=1;i+len-1<=n;i++)
//         {
//             ll d=i+len-1;
//             ll sa=suma[d]-suma[i-1];
//             ll sb=sumb[d]-sumb[i-1];
//             ll sc=sumc[d]-sumc[i-1];
//             ll sf=sumf[d]-sumf[i-1];
//             sa%=2,sb%=2,sc%=2;

//         }
//     }

// }
// signed main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // cin>>_;
//     while (_--)
//     {
//         solve();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

const int MOD = 998244353;

// 快速幂计算 (a^b) % MOD
long long fastPow(long long a, long long b, long long mod)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return result;
}

// 判断一个子串是否为好字符串
bool isGoodString(const string &s)
{
    int countA = 0, countB = 0, countC = 0;
    for (char c : s)
    {
        if (c == 'A')
            countA++;
        else if (c == 'B')
            countB++;
        else if (c == 'C')
            countC++;
    }
    // 满足条件1：每个字符出现偶数次
    if (countA % 2 == 0 && countB % 2 == 0 && countC % 2 == 0)
        return true;
    // 满足条件2：能被3整除
    if ((countA + countB + countC) % 3 == 0)
        return true;
    return false;
}

// 主函数：统计好字符串的替换方式
int countGoodStrings(string S, int K)
{
    int n = S.size();
    int m = count(S.begin(), S.end(), '?');     // 统计问号数量
    int totalReplacements = fastPow(3, m, MOD); // 计算总替换方案数

    vector<int> dp(K + 1, 0); // dp[j] 表示至少有 j 个好字符串的方案数
    dp[0] = totalReplacements;

    // 替换问号并检查好字符串
    for (int mask = 0; mask < (1 << m); ++mask)
    {
        string temp = S;
        int currentMask = mask;
        for (char &c : temp)
        {
            if (c == '?')
            {
                c = "ABC"[currentMask % 3];
                currentMask /= 3;
            }
        }

        // 判断每个子串是否为好字符串
        int goodCount = 0;
        for (int len = 1; len <= n; ++len)
        {
            for (int start = 0; start + len <= n; ++start)
            {
                if (isGoodString(temp.substr(start, len)))
                    goodCount++;
            }
        }

        // 更新dp数组
        for (int j = K; j > 0; --j)
        {
            dp[j] = (dp[j] + dp[j - 1] * goodCount) % MOD;
        }
    }

    return dp[K];
}

int main()
{
    int K, n;
    string S;
    cin >> n >> K;
    cin >> S;
    cout << countGoodStrings(S, K) << endl;
    return 0;
}
