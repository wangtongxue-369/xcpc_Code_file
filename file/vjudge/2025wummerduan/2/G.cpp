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
ll _ = 1, n, m, ans = 0, a[MAXN], x[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    vector<vector<ll>> f(60, vector<ll>(n + 10));
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        f[0][i] = x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int p = 1; p < 60; p++)
    {
        for (int i = 1; i <= n; i++)
        {
            f[p][i] = f[p - 1][f[p - 1][i]];
        }
    }
    vector<ll> q(n + 10);
    for (int i = 1; i <= n; i++)
    {
        q[i] = i;
    }
    for (int p = 0; p < 60; p++)
    {
        if (k % 2)
        {
            for (int i = 1; i <= n; i++)
            {
                q[i] = f[p][q[i]];
            }
        }
        k >>= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[q[i]] << ' ';
    }
    cout << '\n';
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