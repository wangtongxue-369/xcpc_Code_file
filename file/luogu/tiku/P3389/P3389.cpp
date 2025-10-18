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
ll _ = 1, n, m;
double ans[MAXN]; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    vector<vector<double>> a(n + 10, vector<double>(n + 10));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n + 1; j++)
        {
            cin >> a[i][j];
        }
    }
    ll nl = 0;
    for (int i = 1; i <= n; i++)
    {
        ll r = nl;
        for (int j = nl + 1; j <= n; j++)
        {
            if (fabs(a[j][i]) > fabs(a[r][i]))
            {
                r = j;
            }
        }
        if (fabs(a[r][i]) < 1e-7)
        {
            continue;
        }
        swap(a[r], a[i]);

        zhi++;
        double div = a[i][i];
        for (int j = i; j <= n + 1; j++)
        {
            a[i][j] /= div;
        }
        for (int j = i + 1; j <= n; j++)
        {
            double div = a[j][i];
            for (int k = i; k <= n + 1; k++)
            {
                a[j][k] -= a[i][k] * div;
            }
        }
    }
    // 消元完成后的统一判断
    for (int i = 1; i <= n; i++)
    {
        bool all_zero = true;
        for (int j = 1; j <= n; j++)
        {
            if (fabs(a[i][j]) > 1e-7)
            {
                all_zero = false;
                break;
            }
        }
        if (all_zero && fabs(a[i][n + 1]) > 1e-7)
        {
            cout << -1 << '\n';
            return;
        }
    }

    if (zhi < n)
    {
        cout << 0 << '\n';
        return;
    }
    ans[n] = a[n][n + 1];
    for (int i = n - 1; i >= 1; i--)
    {
        ans[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            ans[i] -= a[i][j] * ans[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << "=";
        cout << fixed << setprecision(2) << ans[i] << '\n';
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