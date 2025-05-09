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
    ll x;
    cin >> x;
    if (x < 5)
    {
        cout << -1 << '\n';
        return;
    }
    for (ll i = 0; i <= 31; i++)
    {
        for (ll j = 0; j <= 31; j++)
        {
            if (i == j)
            {
                continue;
            }
            ll y = (1ll << i) + (1ll << j);
            if (y < x && ((1ll << i) & x) && (!((1ll << j) & x)))
            {
                cout << (1ll << i) + (1ll << j) << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
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
