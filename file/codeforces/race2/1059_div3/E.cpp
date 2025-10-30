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
    ll k;
    cin >> n >> k;
    vector<ll> vis(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        vis[a[i]]++;
    }
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ve.push_back(i);
        }
    }
    if (ve.size() == 0)
    {
        for (int i = 1; i <= k; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (ve.size() == 1)
    {
        ll p;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[n])
            {
                p = i;
                break;
            }
        }
        ve.push_back(a[p]);
        ve.push_back(a[n]);
    }
    else if (ve.size() == 2)
    {
        ve.push_back(a[1]);
    }
    for (int i = 0; i < k; i++)
    {
        cout << ve[i % ve.size()] << ' ';
    }
    cout << '\n';
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