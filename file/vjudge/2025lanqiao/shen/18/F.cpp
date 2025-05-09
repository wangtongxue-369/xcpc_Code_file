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
ll _ = 1, n, m, ans = 0, a[110], f[1 << 21];
void solve()
{
    ll k;
    cin >> n >> m >> k;
    memset(f, INF, sizeof(f));
    ll x;
    // cout << f[0] << '\n';
    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            x--;
            sum |= (1ll << x);
        }
        f[sum] = 1;
        a[i] = sum;
    }
    for (int i = 0; i < (1ll << m); i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (f[i] < 1e18)
            {
                f[i | a[j]] = min(f[i | a[j]], f[i] + 1);
            }
        }
    }
    if (f[(1 << m) - 1] > 1e18)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << f[(1 << m) - 1] << '\n';
    }
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
