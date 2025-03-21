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
    ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    ll l = 1;
    ll sum = 0;
    for (int r = 1; r <= n; r++)
    {
        if (a[r] >= 0)
        {
            sum += a[r];
            ans = max(ans, sum);
        }
        else
        {
            if (sum + a[r] >= 0)
            {
                sum += a[r];
                ans = max(ans, sum);
            }
            else
            {
                sum = 0;
                l = r + 1;
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
