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
ll ask(char c, ll k)
{
    cout << "? " << c << ' ' << k << endl;
    ll x;
    cin >> x;
    return x;
}
void solve()
{
    cin >> n;
    vector<PII> ve;
    ll x, y;
    ll ys = -1e18;
    ll yx = -1e18, d = -1e18;
    // cout << n << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        ve.push_back({x, y});
        ys = max(ys, x + y);
        if (d < x + (1e9 - y))
        {
            yx = x - y;
            d = x + (1e9 - y);
        }
    }
    // cout << "!!! " << ys << ' ' << yx << endl;
    ll k = 1e9;
    x = ask('R', k);
    x = ask('R', k);
    x = ask('U', k);
    x = ask('U', k);
    ll p1 = x - 4e9 + ys;
    x = ask('D', k);
    x = ask('D', k);
    x = ask('D', k);
    x = ask('D', k);
    ll p2 = x - 4e9 + yx;
    x = (p1 + p2) / 2, y = (p1 - p2) / 2;
    cout << "! " << x << ' ' << y << endl;
}
// RRUU
// s1+s2 = dx+2e9-x+dy+2e9-y
// DDDD
// s4+s5 = dx+2e9-x1-dy+2e9-y1
// s1+s2-4e9+x+y = dx+dy =p1
// s4+s5-4e9+x1+y1 =dx-dy =p2
//  (p1+p2)/2=dx   (p1-p2)/2=dy
signed main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}