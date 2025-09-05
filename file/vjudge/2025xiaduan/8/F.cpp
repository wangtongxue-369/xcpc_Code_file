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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    vector<vector<char>> a(n + 10, vector<char>(n + 10));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<ll> l(n + 10), h(n + 10);
    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'o')
            {
                sum++;
            }
        }
        h[i] = sum;
    }
    for (int j = 1; j <= n; j++)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j] == 'o')
            {
                sum++;
            }
        }
        l[j] = sum;
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << h[i] << ' ';
    }
    // cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        // cout << l[i] << ' ';
    }
    // cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'o')
            {
                ans += (h[i] - 1) * (l[j] - 1);
            }
        }
    }
    cout << ans << '\n';
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