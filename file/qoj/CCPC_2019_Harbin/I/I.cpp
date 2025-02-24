#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 2e6 + 10;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (a[1] != 0)
    {
        cout << 0 << '\n';
        return;
    }
    if (a[n] != n - 1)
    {
        cout << 0 << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= n)
        {
            cout << 0 << '\n';
            return;
        }
        if (a[i - 1] > a[i])
        {
            cout << 0 << '\n';
            return;
        }
    }
    ll d = 0;
    ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            ans = ans * d % mod;
            d--;
        }
        else
        {
            ans = ans * 2 % mod;
            d += a[i] - a[i - 1] - 1;
        }
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
