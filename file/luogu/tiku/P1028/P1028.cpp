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
    // f[i] 以i结尾的数列，的方案数
    f[1] = 1;
    f[2] = 2;
    f[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 1; j <= i / 2; j++)
        {
            f[i] += f[j];
        }
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