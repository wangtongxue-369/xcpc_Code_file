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
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x]++;
    }
    ans = 0;
    for (int i = 2; i <= 5000; i++)
    {
        if (a[i] >= 2)
        {
            ll p = (a[i] * (a[i] - 1) / 2) % mod;
            for (int j = 1; j <= i / 2; j++)
            {
                if (j == i - j)
                {
                    ans = (ans + p * (a[j] * (a[j] - 1) / 2) % mod) % mod;
                }
                else
                {
                    ans = (ans + p * (a[j] * a[i - j]) % mod) % mod;
                }
            }
        }
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
