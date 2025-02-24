#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    cin >> n;
    ll maxn = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > maxn)
        {
            ans = i;
            maxn = a[i];
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
