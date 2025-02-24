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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n % 2 == 0)
    {

        ans = 1;
        for (int i = 1; i <= n; i += 2)
        {
            ans = max(ans, a[i + 1] - a[i]);
        }
        cout << ans << '\n';
        return;
    }
    else
    {
        ans = 1e18;
        for (int i = 1; i <= n; i++)
        {
            ll minn = 1;
            for (int j = 1; j <= n; j += 2)
            {
                if (i == j)
                {
                    j--;
                    continue;
                }
                minn = max(minn, a[j + 1] - a[j]);
            }
            ans = min(ans, minn);
        }
        cout << ans << '\n';
        return;
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
