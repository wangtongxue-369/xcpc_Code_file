#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll q;
    cin >> n >> q;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (i != 0)
        {
            a[i] += a[i - 1];
        }
    }
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        ll ln = l / n, rn = r / n;
        ll li = l % n, ri = r % n;
        if (ln == rn)
        {
            ll res = 0;
            if (ri > n - 1 - ln)
            {
                res += a[n - 1] - a[ln];
                res += a[ri - (n - ln)];
            }
            else
            {
                res += a[ri + ln] - a[li + ln - 1];
            }
            cout << res << '\n';
        }
        else
        {
            ll res = max(0ll, rn - ln - 1) * sum;
            // cout << res << '\n';
            if (li <= n - 1 - ln)
            {
                cout << '!' << '\n';
                res += a[n - 1] - a[li];
            }
            res += a[ln - 1];

            cout << res << '\n';
            if (ri > n - 1 - rn)
            {
                res += a[n - 1] - a[rn - 1];
                res += a[ri - rn - 1];
            }
            else
            {
                res += a[rn + ri] - a[ri];
            }
            // cout << res << '\n';
        }
        // if (ln == rn)
        // {
        //     // cout << ln << ' ' << rn << '\n';
        //     // cout << li << ' ' << ri << '\n';
        //     ll res = 0;
        //     if (li <= ln)
        //     {
        //         res += a[n] - a[n - li];
        //     }
        //     // cout << res << '\n';
        //     res += a[ri - ln];

        //     cout << res << '\n';
        //     continue;
        // }

        // ll res = max(0ll, rn - ln - 1) * sum;
        // if (li + 1 < ln)
        // {
        //     res += a[n] - a[n - li];
        // }
        // res += a[n - ln];
        // if (ri + 1 < rn)
        // {
        //     res += a[n] - a[n - ri];
        // }
        // res += a[ri - rn];
        // cout << res << '\n';
    }
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
