#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    cin >> n;
    vector<ll> f(n + 10, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            f[j]++;
        }
    }
    ll sum = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = (f[i] + sum) % mod;
        sum = (sum + f[i]) % mod;
    }
    cout << f[n] << '\n';
}
// 每多一组 可以把之前的全部罩起来
//
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