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
    ll k, x;
    cin >> n >> k >> x;
    map<double, ll> ma;
    priority_queue<pair<double, ll>> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    for (auto &it : ma)
    {
        q.push(it);
    }
    while (k)
    {
        auto it = q.top();
        q.pop();
        if (it.second <= k)
        {
            q.push({it.first / 2, it.second * 2});
            k -= it.second;
        }
        else
        {
            q.push({it.first / 2, k * 2});
            q.push({it.first, it.second - k});
            k = 0;
        }
    }
    while (x)
    {
        auto it = q.top();
        // cout << it.first << ' ' << it.second << '\n';
        q.pop();
        if (x <= it.second)
        {
            cout << fixed << setprecision(15) << it.first << '\n';
            return;
        }
        else
        {
            x -= it.second;
        }
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