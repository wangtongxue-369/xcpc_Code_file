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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n >> m;
    ll suma = 0, sumb = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        suma += max(0ll, a[i] - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    ll p = 1;
    for (int i = 1; i <= m; i++)
    {
        ll t = b[i] - 1;
        ll su = 0;
        while (p <= n && su < t)
        {
            ll x = t - su;
            su += min(a[p] - 1, x);
            a[p] -= min(a[p] - 1, x);
            if (a[p] == 1)
            {
                p++;
            }
        }
        b[i] -= su;
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= m; i++)
    // {
    //     cout << b[i] << ' ';
    // }
    // cout << '\n';
    p = 1;
    ll ex = 0;
    ll p1 = 1, p2 = 1;
    while (p1 <= n + 1 && p2 <= m)
    {
        while (b[p2] > 0 && p1 <= n)
        {
            // cout << "! " << p1 << ' ' << p2 << ' ' << a[p1] << ' ' << b[p2] << '\n';
            ll t = min(a[p1], b[p2]);
            a[p1] -= t;
            b[p2] -= t;
            if (a[p1] <= 0)
            {
                ex++;
                b[p2]--;
            }
            p1++;
            a[p1] -= ex;
        }
        // cout << "!! " << p1 << ' ' << p2 << ' ' << a[p1] << ' ' << b[p2] << '\n';
        while (p1 <= n)
        {
            if (a[p1] <= ex)
            {
                a[p1] = 0;
                ex++;
                p1++;
            }
            else
                break;
        }
        if (b[p2] > 0 && p1 > n)
        {
            cout << "1NO\n";
            return;
        }
        if (b[p2] <= 0)
        {
            ex++;
            p2++;
        }
    }
    if (p2 == m + 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    // sort(b + 1, b + 1 + m);
    //  for (int i = 1; i <= n; i++)
    //  {
    //      cout << a[i] << ' ';
    //  }
    //  cout << '\n';
    //  for (int i = 1; i <= m; i++)
    //  {
    //      cout << b[i] << ' ';
    //  }
    //  cout << '\n';
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