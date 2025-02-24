#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 550;
ll _ = 1, n, m, ans = 0, a[MAXN][MAXN], f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    ans = 0;
    for (int s = 1; s <= n; s++)
    {
        ll j = s;
        ll minn = 0;
        ll i = 1;
        while (i <= n - s + 1)
        {

            minn = min(minn, a[i][j]);
            i++;
            j++;
        }
        ans += abs(minn);
    }
    for (int s = 2; s <= n; s++)
    {
        ll j = s;
        ll minn = 0;
        ll i = 1;
        while (i <= n - s + 1)
        {

            minn = min(minn, a[j][i]);
            i++;
            j++;
        }
        ans += abs(minn);
    }

    // for (int j = 1; j <= n; j++)
    // {
    //     ll i = 1;
    //     ll minn = 0;
    //     while (i <= n - j + 1)
    //     {
    //         minn = min(minn, a[i][j]);
    //         i++;
    //     }
    //     ans += abs(minn);
    // }
    // for (int j = n - 1; j >= 1; j--)
    // {
    //     ll i = n;
    //     ll minn = 0;
    //     while (i <= j)
    //     {
    //         minn = min(minn, a[i][j]);
    //         i--;
    //     }
    //     ans += abs(minn);
    // }
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
