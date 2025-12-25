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
    ll n, x;
    cin >> n >> x;
    vector<ll> xa(n + 10), da(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        xa[i] = a[i];
        da[i] = a[i];
    }
    ll minn = 0;
    if (xa[1] == -999)
    {
        xa[1] = -50;
    }
    for (int i = 2; i <= n; i++)
    {
        if (xa[i] == -999)
        {
            xa[i] = max(xa[i - 1] - x + 1, (ll)-50);
        }
        if (xa[i - 1] - xa[i] >= x)
        {
            minn++;
        }
    }
    ll maxn = 0;
    if (da[1] == -999)
    {
        da[1] = 50;
    }
    for (int i = 2; i <= n; i++)
    {
        if (da[i] == -999)
        {
            if (da[i - 1] - x < (ll)-50)
            {
                da[i] = 50;
            }
            else
            {
                da[i] = da[i - 1] - x;
            }
        }
        if (da[i - 1] - da[i] >= x)
        {
            maxn++;
        }
    }
    cout << maxn << ' ' << minn << '\n';
    priority_queue<ll> q;
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