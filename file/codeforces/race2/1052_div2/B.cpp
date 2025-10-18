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
    cin >> n >> m;
    vector<ll> cnt(m + 10);
    vector<vector<ll>> ve(n + 10);
    ll x, l;
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        for (int j = 1; j <= l; j++)
        {
            cin >> x;
            ve[i].push_back(x);
            cnt[x]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (cnt[i] == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll flag = 1;
        for (auto it : ve[i])
        {
            if (cnt[it] == 1)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    if (ans >= 2)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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