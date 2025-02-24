#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
// const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N]; // f[N];
ll f[250][250];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 2; i <= n + 1; i++)
    {
        for (int l = 1; l + i - 1 <= 2 * n; l++)
        {
            int r = l + i - 1;
            for (int k = l + 1; k <= l + i - 2; k++)
            {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + a[l] * a[k] * a[r]);
                ans = max(ans, f[l][r]);
            }
        }
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
