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
    n = 5;
    for (int i = 1; i <= n; i++)
    {
        // cin >> a[i];
        // a[i] *= 2;
    }
    ans = 0;
    double p = 0.5;
    ll cnt = 0;
    function<void(double x, ll cnt, ll i)> dfs = [&](double x, ll cnt, ll i)
    {
        if (i == n + 1)
        {
            ans = max(cnt, ans);
            return;
        }
        bool p = (x < 0);
        double xx = x + a[i];
        bool p1 = (xx < 0);
        ll nc = cnt;
        if (p != p1)
        {
            nc++;
            dfs(xx, nc, i + 1);
        }
        else
        {
            dfs(xx, nc, i + 1);
        }
        xx = x - a[i];
        bool p2 = (xx < 0);
        nc = cnt;
        if (p != p2)
        {
            nc++;
            dfs(xx, nc, i + 1);
        }
        else
        {
            dfs(xx, nc, i + 1);
        }
    };
    dfs(0.5, 0, 1);
    // cout << ans << '\n';
    p = 0.5;
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        double pp = p;
        if (p > 0)
        {
            p -= a[i];
        }
        else
        {
            p += a[i];
        }
        if (pp > 0 != p > 0)
        {
            cnt++;
        }
    }
    // cout << cnt << '\n';
    if (ans != cnt)
    {
        cout << ans << ' ' << cnt << '\n';
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (a[1] = 1; a[1] <= 10; a[1]++)
    {
        for (a[2] = 1; a[2] <= 10; a[2]++)
        {
            for (a[3] = 1; a[3] <= 10; a[3]++)
            {
                for (a[4] = 1; a[4] <= 10; a[4]++)
                {
                    for (a[5] = 1; a[5] <= 10; a[5]++)
                    {
                        solve();
                    }
                }
            }
        }
    }

    // cin >> _;
    // while (_--)
    // {
    //     solve();
    // }
    return 0;
}