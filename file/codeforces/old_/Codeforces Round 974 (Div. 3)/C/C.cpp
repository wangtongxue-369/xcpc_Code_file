#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];
void solve()
{
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (n <= 2)
    {
        cout << "-1" << '\n';
        return;
    }
    sort(a + 1, a + 1 + n);
    ll d = ceil(1.0 * n / 2);
    ll sum2 = n * a[d];
    ans = a[n / 2 + 1] * 2 * n - sum + 1;
    cout << max(0ll, ans) << '\n';
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
