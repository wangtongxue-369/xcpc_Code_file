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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (abs(a[i] - a[i - 1]) <= 1)
        {
            cout << 0 << '\n';
            return;
        }
    }
    ans = 10000;
    for (int i = 1; i <= n; i++)
    {
        ll maxn = a[i], minn = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            maxn = max(maxn, a[j]);
            minn = min(minn, a[j]);
            if (j + 1 <= n && (minn - 1 <= a[j + 1] || a[j + 1] <= maxn + 1))
            {
                ans = min(ans, (ll)j - i);
                break;
            }
            if (i - 1 >= 1 && (minn - 1 <= a[i - 1] || a[i - 1] <= maxn + 1))
            {
                ans = min(ans, (ll)j - i);
                break;
            }
        }
    }
    if (ans == 10000)
    {
        cout << -1 << '\n';
        return;
    }
    cout << ans << '\n';
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