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
    cin >> n;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    ans = 0;
    ll tmp = 0;
    vector<ll> ji;
    ll cnt = 0;
    for (auto it : ma)
    {
        tmp += it.first * (it.second - it.second % 2);
        if (it.second % 2 == 0)
        {
            cnt += it.second;
        }
        if (it.second % 2)
        {
            ji.push_back(it.first);
        }
    }
    if (tmp == 0)
    {
        cout << 0 << '\n';
        return;
    }
    if (cnt > 3)
    {
        ans = tmp;
    }
    for (auto it : ma)
    {
        if (it.second % 2)
        {
            if (it.first < tmp)
            {
                ans = max(ans, tmp + it.first);
            }
        }
    }
    if (ji.size() > 1)
    {
        for (int i = 0; i < ji.size() - 1; i++)
        {
            if (ji[i + 1] - ji[i] < tmp)
            {
                ans = max(ans, tmp + ji[i + 1] + ji[i]);
            }
        }
    }
    cout << ans << '\n';
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