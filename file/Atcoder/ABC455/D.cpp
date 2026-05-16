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
ll _ = 1, n, m, ans = 0, a[MAXN], up[MAXN], down[MAXN];
void solve()
{
    ll n, q;
    cin >> n >> q;

    while (q--)
    {
        ll c, p;
        cin >> c >> p;
        ll d = down[c];
        if (d != 0)
        {
            up[d] = 0;
            down[c] = 0;
        }
        up[p] = c;
        down[c] = p;
    }
    for (int i = 1; i <= n; i++)
    {
        if (down[i] == 0)
        {
            ll p = i;
            ll cnt = 0;
            while (p != 0)
            {
                cnt++;
                p = up[p];
            }
            a[i] = cnt;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << ' ';
    }
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