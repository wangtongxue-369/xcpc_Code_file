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
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<ll> b(100, 0);
    ans = 0;
    for (int i = 55; i >= 0; i--)
    {
        if (i == 0)
        {
            if (sum > 0)
            {
                ans += 1;
            }
        }
        else
        {
            if (sum <= ((1ll << i) * n - n))
            {
                continue;
            }
            if (sum > ((1ll << i) * n - n))
            {
                ll cs = (sum / (1ll << i));
                sum -= cs * (1ll << i);
                ans += (1ll << i);
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
