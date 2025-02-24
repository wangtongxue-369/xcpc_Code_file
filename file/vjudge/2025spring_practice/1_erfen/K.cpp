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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    function<bool(ll x)> check = [&](ll x)
    {
        ll sum = 0, s;
        vector<ll> b(n + 10, 0);
        for (int i = 1; i <= n; i++)
        {
            // cout << i << ' ';
            if (i == n && b[i] >= x)
            {
                continue;
            }
            b[i] += a[i];
            sum++;
            if (b[i] >= x)
            {
                continue;
            }
            else
            {
                s = ceil(1.0 * (x - b[i]) / a[i]);
                b[i] = b[i] + s * a[i];
                b[i + 1] += a[i + 1] * s;
                sum += (2 * s);
            }
        }
        if (sum <= m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    };
    ll l = 0, r = 1000000000000;
    while (l < r)
    {
        // cout << l << '\n';
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << (ll)l << '\n';
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
