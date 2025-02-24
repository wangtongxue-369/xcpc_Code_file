#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 1000050;
ll _ = 1, n, m, ans = 0, a[MAXN]; // f[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<ll> ve(n + 100, 0);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x = 0;
        ll tmp = i;
        while (ve[tmp] == 0)
        {
            ve[tmp] = 1;
            tmp = a[tmp];
            x++;
        }
        // x==2 dai biao man zu 2
        if (x >= 3)
        {
            ans += (x - 1) / 2;
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
