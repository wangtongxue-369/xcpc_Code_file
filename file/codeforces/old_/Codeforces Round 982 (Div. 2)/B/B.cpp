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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] > a[i])
            {
                sum++;
            }
        }
        ans = min(ans, sum + i - 1);
    }
    cout << ans << '\n';
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
