#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ull f(ull n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else
        return 0;
}

ull g(ull n, ull i, ull k)
{
    if (i == 0)
    {
        if (k == 0)
            return f(n);
        else
            return 0; // 当i=0且k≠0时，无满足条件的x
    }
    ull pow2 = 1ULL << i;
    // 如果n小于k，则没有满足条件的x
    if (n < k)
        return 0;
    ull m = (n - k) / pow2;
    ull cnt = m + 1;
    ull res = f(m) << i;
    if (cnt % 2 == 1)
        res ^= k;
    return res;
}

void solve()
{
    ull l, r, k;
    int i;
    cin >> l >> r >> i >> k;
    ull sum = f(r) ^ f(l - 1);
    ull Xor = g(r, i, k) ^ g(l - 1, i, k);
    ull ans = sum ^ Xor;
    cout << ans << "\n";
}
signed main()
{
    int _;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
