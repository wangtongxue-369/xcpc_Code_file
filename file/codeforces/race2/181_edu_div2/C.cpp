/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
ll get(ll x)
{
    ll res = 0;
    res += x / 2 + x / 3 + x / 5 + x / 7;
    res -= x / 6;
    res -= x / 10;
    res -= x / 14;
    res -= x / 15;
    res -= x / 21;
    res -= x / 35;
    res += x / 30;
    res += x / 42;
    res += x / 70;
    res += x / 105;
    res -= x / 210;
    return x - res;
}
void solve()
{
    ll l, r;
    cin >> l >> r;
    if ((l <= r))
    {
        cout << get(r) - get(l - 1) << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}
// 不能是2，3，5，7的倍数
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