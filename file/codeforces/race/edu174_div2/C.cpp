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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll s1 = 0, s2 = 0, s3 = 0;
    // 答案一定是由1开始，中间一堆2，最后一个为3
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 2)
        {
            s2 = 2 * s2 % mod;
            s2 = (s2 + s1) % mod;
            continue;
        }
        if (a[i] == 1)
        {
            s1++;
        }
        if (a[i] == 3)
        {
            s3 = (s3 + s2) % mod;
        }
    }
    cout << s3 << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
