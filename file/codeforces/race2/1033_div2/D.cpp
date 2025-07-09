#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
#define int long long
const int MOD = 1e9 + 7;
const int MAX = 100005;
vector<int> fact(MAX), invfact(MAX);

// 快速幂
int modpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

// 初始化阶乘与逆阶乘
void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    invfact[MAX - 1] = modpow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; --i)
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
}

// 组合数 C(n, k)
int comb(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}
void solve()
{
    ll a, b, k;
    cin >> a >> b >> k;
    // (a-1)*k+1
    n = (a - 1) * k % mod + 1;
    n %= mod;
    // (b-1)*k*C(n,a)+1
    ll C = 1;
    ll num = 1;
    for (int i = 0; i < a; i++)
    {
        num = num * ((n - i + mod) % mod) % mod;
    }
    C = num * invfact[a] % mod;
    // cout << C << ' ' << num << '\n';
    m = ((b - 1) % MOD) * (k % MOD) % MOD;
    m = m * C % MOD;
    m = (m + 1) % MOD;
    cout << n << ' ' << m << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}