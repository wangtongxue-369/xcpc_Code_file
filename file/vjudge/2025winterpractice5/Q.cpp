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
void solve()
{
    cin >> n >> m;
    set<ll> s1, s2;
    ll x;
    for (int i = 1; i <= 2 * max(n, m) + 10; i++)
    {
        a[i] = 0, f[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x]++;
    }
    ll same = 0, ns = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        f[x]++;
    }
    for (int i = 1; i <= 2 * max(n, m); i++)
    {
        if (a[i] && f[i])
        {
            same++;
        }
        if ((a[i] == 0 && f[i]) || (a[i] && f[i] == 0))
        {
            ns++;
        }
    }
    cout << (ll)(1.0 * same / (same + ns) * 100) << '\n';
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