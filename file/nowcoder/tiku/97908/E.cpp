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
    cin >> n;
    double sum = 0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        sum += 1.0 / i;
    }
    printf("%.10lf", 1.0 - sum);
}
// 一个数据里面大于n/2的环只会有一个
// 考虑找这个环
// 对于所有排列，有n！种
// 对于环长度为s的环
// 首先固定开头C(n,s)情况
// 剩下的全排列(s-1)!    再剩下的就是(n-s)!
// 所以最后长度为s的环的情况数为C(n,s)*(s-1)!*(n-s)!
// C(n,s)可以拆为n!/(s!(n-s)!)
// 得n!/s
// 那么就需要枚举长度就可以
// 最后再除以所有情况的n！
// 就可以得到答案为sum(1/s)(n/2+1<=s<=n)
// 减一就可以得到最终答案
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
