#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];
void solve()
{
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i - 1] - '0';
    }
    for (int i = 1; i <= k; i++)
    {
        // ll sum = 0;
        ll sum2 = 0, sum5 = 0, sum0 = 0;
        for (int j = 1; j < i; j++)
        {
            // cout << '!' << '\n';
            if (a[j] % 2 == 0 && a[j] != 0)
            {
                sum2 += a[j] / 2;
            }
            if (a[j] == 5)
            {
                sum5++;
            }
            if (a[j] == 0)
            {
                sum0++;
            }
        }
        for (int j = n - k + i; j <= n; j++)
        {
            // cout << "!!" << ' ' << j << '\n';
            if (a[j] % 2 == 0 && a[j] != 0)
            {
                sum2 += a[j] / 2;
            }
            if (a[j] == 5)
            {
                sum5++;
            }
            if (a[j] == 0)
            {
                sum0++;
            }
        }
        // cout << sum0 << ' ' << sum2 << ' ' << sum5 << '\n';
        if (sum0)
        {
            ans = max(ans, 1ll);
            continue;
        }

        ans = max(ans, min(sum2, sum5));
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
