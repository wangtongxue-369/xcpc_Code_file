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
    ll s1, s2;
    cin >> s1 >> s2;
    ll ws1 = 0;
    ll p = s1;
    if (s1 == s2)
    {
        cout << 0 << '\n';
        return;
    }
    bool flag = 0;
    vector<ll> ve;
    for (int i = 34; i >= 0; i--)
    {
        if (flag == 0 && !(s1 & (1ll << i)) && (s2 & (1ll << i)))
        {
            cout << -1 << '\n';
            return;
        }
        if ((s1 & (1ll << i)) && (s2 & (1ll << i)))
        {
            flag = 1;
            break;
        }
        if ((s1 & (1ll << i)) && !(s2 & (1ll << i)))
        {
            flag = 1;
            break;
        }
        if (!(s1 & (1ll << i)) && (s2 & (1ll << i)))
        {
            flag = 1;
            break;
        }
    }
    for (int i = 0; i <= 34; i++)
    {
        if ((s1 & (1ll << i)) && (s2 & (1ll << i)))
        {
            continue;
        }
        if ((s1 & (1ll << i)) && !(s2 & (1ll << i)))
        {
            ve.push_back({1ll << i});
        }
        if (!(s1 & (1ll << i)) && (s2 & (1ll << i)))
        {
            ve.push_back({1ll << i});
        }
    }
    cout << ve.size() << '\n';
    for (auto it : ve)
    {
        cout << it << '\n';
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