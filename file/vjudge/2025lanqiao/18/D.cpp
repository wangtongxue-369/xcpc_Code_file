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
ll _ = 1, n, m, ans = 0, f[1050][55]; // f[MAXN];
void solve()
{
    ll k, p, l;
    cin >> k >> p >> l;
    f[0][0] = 1;
    for (int i = 1; i <= l; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                if (j < p)
                {
                    for (int w = 0; w <= k; w++)
                    {
                        f[i][j] = (f[i][j] + f[i - j][w]) % mod;
                    }
                }
                else
                {
                    for (int w = 0; w <= p - 1; w++)
                    {
                        f[i][j] = (f[i][j] + f[i - j][w]) % mod;
                    }
                }
            }
        }
    }
    ans = 0;
    for (int j = 1; j <= k; j++)
    {
        ans = (ans + f[l][j]) % mod;
    }
    cout << ans << '\n';
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
