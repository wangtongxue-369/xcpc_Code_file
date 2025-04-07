#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 20201114;

// 快速求模加减乘（注意MOD可能不是素数，但这里只用作加法乘法）
inline ll add(ll a, ll b)
{
    a += b;
    return a >= MOD ? a - MOD : a;
}
inline ll sub(ll a, ll b)
{
    a -= b;
    return a < 0 ? a + MOD : a;
}
inline ll mul(ll a, ll b) { return (a % MOD) * (b % MOD) % MOD; }

// 这里我们采用常见的线性递推求第 n 项的模板
// 给定递推 f(n) = c[1]*f(n-1) + ... + c[d]*f(n-d)  (n>=d)
// initial: f(0),..., f(d-1)
// 求 f(n) mod MOD, 其中 n 可达10^18
//
// 使用的是二次时间的多项式“倍增”算法，其核心在于
// 求出多项式 Q(x) = x^n (mod the characteristic polynomial)
// 然后 f(n) = sum_{i=0}^{d-1} Q_i * f(i).

// 将两个多项式 a(x) 和 b(x) 相乘后取模 poly（代表特征多项式）
// a, b 的次数均 < d，返回乘积模 poly 后次数仍 < d 的多项式
vector<ll> polyMul(const vector<ll> &a, const vector<ll> &b, const vector<ll> &poly)
{
    int d = poly.size();
    vector<ll> res(2 * d - 1, 0);
    for (int i = 0; i < (int)a.size(); i++)
    {
        for (int j = 0; j < (int)b.size(); j++)
        {
            res[i + j] = add(res[i + j], mul(a[i], b[j]));
        }
    }
    // 降次：对于 i>=d，利用特征多项式 poly: x^d = c[1]*x^(d-1)+...+c[d]
    for (int i = 2 * d - 2; i >= d; i--)
    {
        // poly[j]对应 x^(d-j) 的系数（poly[0] 应为1）
        for (int j = 1; j <= d; j++)
        {
            res[i - j] = add(res[i - j], mul(res[i], poly[j]));
        }
    }
    res.resize(d);
    return res;
}

// 快速幂思想：计算 x^n mod poly，其中初始多项式 x 被表示为 [0,1,0,...,0]（即系数 0 次为0,1次为1）
vector<ll> polyPow(ll n, const vector<ll> &poly)
{
    int d = poly.size();
    vector<ll> res(d, 0), base(d, 0);
    res[0] = 1;  // 常数项1
    base[1] = 1; // x
    while (n)
    {
        if (n & 1)
            res = polyMul(res, base, poly);
        base = polyMul(base, base, poly);
        n >>= 1;
    }
    return res;
}

// 求线性递推 f(n) 的第 n 项
// rec: 递推系数 [c1, c2, ..., cd] (长度 d)
// init: 初始值 f(0)...f(d-1)
// n: 要计算的项（0-indexed）
// 特征多项式为: P(x) = x^d - c1*x^(d-1) - ... - cd, 我们将其表示为 poly, 长度 d+1，形式为:
// poly[0]=1, poly[i] = -c[i] mod MOD, i=1...d.
ll linearRecurrence(ll n, const vector<ll> &rec, const vector<ll> &init)
{
    int d = rec.size();
    if (n < d)
        return init[n] % MOD;
    // 构造特征多项式 poly
    vector<ll> poly(d + 1, 0);
    poly[0] = 1;
    for (int i = 0; i < d; i++)
    {
        poly[i + 1] = (MOD - rec[i] % MOD) % MOD;
    }
    // 将多项式降维为长度 d：poly[0..d-1] 表示 x^d = -poly[1..d] 的关系
    // 我们只需要 poly[1..d]，将其放到长度 d 的数组中（注意索引对应：poly[i] for i>=1）
    vector<ll> charPoly(d, 0);
    for (int i = 0; i < d; i++)
    {
        charPoly[i] = poly[i + 1];
    }
    // 求多项式 x^n mod 特征多项式。注意我们使用的 polyMul 函数要求模多项式形式为：
    // x^d = c[0]*x^(d-1)+ ... + c[d-1], 即多项式为 [c0, c1, ..., c[d-1]].
    // 这里我们令 polyMod = charPoly，即 charPoly[i] = coefficient用于 x^(d-i).
    // 最后得到的 Q(x)= q0 + q1*x+...+q_{d-1}*x^{d-1} 满足 f(n)= sum_{i=0}^{d-1} q_i f(i).
    vector<ll> Q = polyPow(n, charPoly);
    ll ans = 0;
    for (int i = 0; i < d; i++)
    {
        ans = (ans + mul(Q[i], init[i])) % MOD;
    }
    return ans;
}

// 主函数
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll k, p, L;
    cin >> k >> p >> L;

    // 特判：如果 p == 1，则任何两步跳都是大跳（因为每步 >=1），连续两步大跳会摔倒，
    // 故只有单步方案可以走完 (如果 L<=k)，否则无解。
    if (p == 1)
    {
        if (L <= k)
            cout << 1 % MOD << "\n";
        else
            cout << 0 << "\n";
        return 0;
    }

    // d = k + p - 1，递推阶数
    int d = k + p - 1;
    // 计算递推系数 c[1..d]（这里存到 vector rec, 下标 0..d-1 表示 c1...cd）
    vector<ll> rec(d, 0);
    // 对于 m = 1 .. d：
    // 第一部分：当 m <= p-1，则有一项来自 A(x)
    for (int m = 1; m <= p - 1; m++)
    {
        if (m <= d)
            rec[m - 1] = add(rec[m - 1], 1);
    }
    // 第二部分：来自 A(x)*B(x)
    // 对 i = 1..p-1, 对 j = p..k, m = i+j
    for (int i = 1; i <= p - 1; i++)
    {
        for (int j = p; j <= k; j++)
        {
            int m = i + j;
            if (m <= d)
                rec[m - 1] = add(rec[m - 1], 1);
        }
    }

    // 计算 f(n) 的初始值 f(0) ... f(d-1)
    // 状态 dp[len][state]，其中 state: 0 表示最后一次跳是“小跳”（或初始状态），1 表示“大跳”
    vector<vector<ll>> dp(d + 1, vector<ll>(2, 0));
    dp[0][0] = 1; // 初始状态
    for (int len = 0; len < d; len++)
    {
        for (int st = 0; st < 2; st++)
        {
            if (dp[len][st] == 0)
                continue;
            // 对每一步可以选择跳距离 x=1..k，但总长不超过 d
            for (int x = 1; x <= k; x++)
            {
                if (len + x > d)
                    break;
                // 若当前状态 st==1（上一步为大跳），则本步必须为小跳（x < p）
                if (st == 1)
                {
                    if (x < p)
                    {
                        dp[len + x][0] = add(dp[len + x][0], dp[len][st]);
                    }
                }
                else
                { // st==0
                    if (x < p)
                    {
                        dp[len + x][0] = add(dp[len + x][0], dp[len][st]);
                    }
                    else
                    {
                        dp[len + x][1] = add(dp[len + x][1], dp[len][st]);
                    }
                }
            }
        }
    }
    // f(n) 为两状态之和
    vector<ll> init(d, 0);
    for (int n = 0; n < d; n++)
    {
        init[n] = add(dp[n][0], dp[n][1]);
    }

    // 注意：f(0) 表示空序列（方案数为 1），而题目要求的是走完 L 跳的方案数，
    // 即 f(L) 当 L>=1。现在利用线性递推算法求 f(L) mod MOD.
    ll ans = linearRecurrence(L, rec, init);
    cout << ans % MOD << "\n";
    return 0;
}
