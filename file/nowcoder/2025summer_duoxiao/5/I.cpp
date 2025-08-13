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
ll get(ll x, ll y)
{
    x = x ^ y;
    ll cnt = 0;
    for (int i = 0; i <= 32; i++)
    {
        if (x & (1ll << i))
        {
            cnt++;
            if (cnt % 2 == 0)
            {
                x -= (1ll << i);
            }
        }
    }
    return x;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= 32; i++)
    {
        ll sum1 = 0, sum0 = 0;
        for (int i = 1; i <= n; i++)
        {
        }
    }
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