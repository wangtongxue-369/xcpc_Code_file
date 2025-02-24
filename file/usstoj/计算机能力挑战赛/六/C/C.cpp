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
        a[i] += a[i - 1];
    }
    if (a[n] % 3 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    ll sum = 0;
    for (int i = 2; i <= n - 1; i++)
    {
        if (a[i - 1] == a[n] / 3)
        {
            sum++;
        }
        if ((a[n] - a[i]) == a[n] / 3)
        {
            ans += sum;
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
