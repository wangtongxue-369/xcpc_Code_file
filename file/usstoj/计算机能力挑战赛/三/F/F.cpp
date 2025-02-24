#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    cin >> n >> m;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        // cout << sum << '\n';
        if (sum + a[i] > m)
        {
            sum = a[i];
            ans++;
        }
        else
        {
            sum += a[i];
        }
    }
    cout << ans + 1 << '\n';
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
