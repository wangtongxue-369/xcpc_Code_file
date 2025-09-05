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
void solve()
{
    cin >> n >> m;
    vector<ll> v;
    ll nor = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    vector<ll> cf(2 * n + 10);
    for (int i = 2; i <= m; i++)
    {
        ll x = abs(a[i] - a[i - 1]);
        if (a[i - 1] < a[i])
        {
            if (x <= n - x)
            {
                cf[a[i - 1]] += (n - x) - x;
                cf[a[i]] -= (n - x) - x;
            }
            else
            {
                cf[1] += x - (n - x);
                cf[a[i - 1]] -= x - (n - x);

                cf[a[i]] += x - (n - x);
            }
        }
        else
        {
            if (x <= n - x)
            {
                cf[a[i]] += (n - x) - x;
                cf[a[i - 1]] -= (n - x) - x;
            }
            else
            {
                cf[a[i - 1]] += x - (n - x);
                cf[1] += x - (n - x);
                cf[a[i]] -= x - (n - x);
            }
        }
        nor += min(x, n - x);
    }
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        // cout << cf[i] << ' ';
    }
    // cout << '\n';
    // cout << nor << '\n';
    for (int i = 1; i <= 2 * n; i++)
    {
        cf[i] += cf[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, nor + cf[i]);
    }
    cout << ans << '\n';
}
// min(t-s,n-(t-s))
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