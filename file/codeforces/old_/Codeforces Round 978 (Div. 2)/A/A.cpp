#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll r, sum = 0;
    ans = 0;
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            r -= a[i] / 2;
            ans += a[i];
        }
        else
        {
            r -= a[i] / 2;
            ans += 2 * (a[i] / 2);
            sum++;
        }
    }
    if (sum <= r)
    {
        cout << ans + sum << '\n';
        return;
    }
    else
    {
        cout << ans + r * 2 - sum << '\n';
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
