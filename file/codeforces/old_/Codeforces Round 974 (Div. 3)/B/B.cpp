#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 500005;
ll _ = 1, n, m, ans = 0, a[500005], f[500005];
void solve()
{
    ll k;
    cin >> n >> k;
    ll d = k;
    ll ou = 0, ji = 0;
    if (d % 2 == 0)
    {
        ji = d / 2;
        ou = d / 2;
    }
    else
    {
        if (n % 2 == 0)
        {
            ji = d / 2;
            ou = d / 2 + 1;
        }
        else
        {
            ji = d / 2 + 1;
            ou = d / 2;
        }
    }
    if (ji % 2 == 0)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
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
