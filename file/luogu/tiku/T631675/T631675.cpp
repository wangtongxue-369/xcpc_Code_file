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
    ll k;
    cin >> n >> k;
    // f[i] 收尾不相同的情况数
    // g[i] 首位相同的方案数
    // g[i]=f[i-1] 在i的位置强行放上一个和首相同的
    // f[i]=f[i-1]*(k-2)+g[i-1]*(k-1)
    // f[i]=f[i-1]*(k-2)+g[i-2]*(k-1)
    f[1] = k;
    f[2] = k * (k - 1) % mod;
    f[3] = k * (k - 1) * (k - 2) % mod;
    for (int i = 4; i <= n; i++)
    {
        f[i] = f[i - 1] * (k - 2) + f[i - 2] * (k - 1);
        f[i] %= mod;
    }
    cout << f[n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}