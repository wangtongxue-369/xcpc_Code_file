#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lld 0x3f
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, q, a[500005], f[500005];
void solve()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    ll b;
    sort(a + 1, a + 1 + m);
    while (q--)
    {
        cin >> b;
        ll pos = lower_bound(a + 1, a + 1 + m, b) - a;
        // cout << '!' << pos << '\n';
        if (pos > m || pos < 1)
        {
            cout << n - a[m] << '\n';
            continue;
        }
        if (a[pos] == b)
        {
            cout << 0 << '\n';
            continue;
        }

        if (pos == 1)
        {
            cout << a[1] - 1 << '\n';
            continue;
        }
        cout << (a[pos] - a[pos - 1]) / 2 << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
