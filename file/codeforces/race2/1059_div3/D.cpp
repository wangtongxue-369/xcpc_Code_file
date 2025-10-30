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
ll ask1(ll l, ll r)
{
    cout << 1 << ' ' << l << ' ' << r << endl;
    ll x;
    cin >> x;
    return x;
}
ll ask2(ll l, ll r)
{
    cout << 2 << ' ' << l << ' ' << r << endl;
    ll x;
    cin >> x;
    return x;
}
void solve()
{
    cin >> n;
    ll len = ask2(1, n) - (1 + n) * n / 2;
    ll l = 1, r = n;
    ans = 0;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        ll x = ask2(1, mid) - ask1(1, mid);
        if (x == 0)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (ask2(1, l) - ask1(1, l) == 0)
    {
        cout << "! " << l + 1 << ' ' << l + 1 + len - 1 << endl;
    }
    else
    {
        cout << "! " << 1 << ' ' << len << endl;
    }
}

signed main()
{
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
