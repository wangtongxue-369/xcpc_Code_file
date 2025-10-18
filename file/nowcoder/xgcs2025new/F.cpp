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
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll get(ll n)
{
    ll l = 1, r = 2e18;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        __int128_t sum = (__int128_t)mid * ((__int128_t)mid + 1) / 2;
        if (sum >= (__int128_t)n)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
void solve()
{
    cin >> n;
    // a[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     a[i] = a[i - a[i - 1]] + 1;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    ll c = n * 2;
    cout << get(n) << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}