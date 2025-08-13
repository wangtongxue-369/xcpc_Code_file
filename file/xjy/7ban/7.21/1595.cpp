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
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            continue;
        }
        f[i]++;
        for (int j = max(1ll, i - a[i]); j < i; j++)
        {
            f[j]++;
        }
        for (int j = i + 1; j <= min(n, i + a[i]); j++)
        {
            f[j]++;
        }
    }
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, f[i]);
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}