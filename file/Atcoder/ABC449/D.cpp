/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll u, d, l, r;
    cin >> l >> r >> d >> u;
    for (int i = u; i >= d; i--)
    {
        ll t = abs(i);
        ll l1 = max(l, -t);
        ll r1 = min(r, t);
        if (t % 2 == 0)
        {
            if (l1 <= r1)
            {
                ans += r1 - l1 + 1;
            }
        }
        ll l2 = l;
        ll r2 = min(r, -t - 1);
        ll ff;
        if (l2 % 2 == 0)
        {
            ff = l;
        }
        else
        {
            ff = l + 1;
        }
        if (l2 <= r2 && ff <= r2)
        {
            ans += (r2 - ff) / 2 + 1;
        }
        ll l3 = max(l, t + 1);
        ll r3 = r;
        if (l3 % 2 == 0)
        {
            ff = l3;
        }
        else
        {
            ff = l3 + 1;
        }
        if (l3 <= r3 && ff <= r3)
        {
            ans += (r3 - ff) / 2 + 1;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}