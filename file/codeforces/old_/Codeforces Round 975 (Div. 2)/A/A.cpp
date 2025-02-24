#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[N], f[N];
void solve()
{
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            ans = max(ans, a[i] + n / 2 + n % 2);
        }
        else
        {
            ans = max(ans, a[i] + n / 2);
        }
    }
    cout << ans << '\n';
    // if (n % 2 == 1)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {

    //         if (i % 2 == 1)
    //         {
    //             ans = max(ans, a[i] +ceil(1.0*n/2));
    //         }
    //         else{
    //             ans=max(ans,a[i]+n/2);
    //         }
    //     }
    // }
    // else{
    //     for (int i = 1; i <= n; i++)
    //     {

    //         if (i % 2 == 1)
    //         {
    //             ans = max(ans, a[i] +ceil(1.0*n/2));
    //         }
    //         else{
    //             ans=max(ans,a[i]+n/2);
    //         }
    //     }
    // }
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
