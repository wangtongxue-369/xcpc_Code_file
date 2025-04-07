#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 20201114;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[1050][10];
void solve()
{
    ll k, p, l;
    cin >> k >> p >> l;
    f[0][0] = 1;
    for (int i = 1; i <= l; i++)
    {
        // f[i][0]
        for (int j = 1; j <= p - 1; j++)
        {
            if (i - j >= 0)
            {
                f[i][0] = (f[i][0] + f[i - j][0] + f[i - j][1]) % mod;
            }
        }
        for (int j = p; j <= k; j++)
        {
            if (i - j >= 0)
            {
                f[i][1] = (f[i][1] + f[i - j][0]) % mod;
            }
        }
    }
    cout << (f[l][0] + f[l][1]) % mod << '\n';
}
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
