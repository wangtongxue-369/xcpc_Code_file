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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
ll ask(ll i, ll x)
{
    cout << "? " << i << ' ' << x << endl;
    cin >> x;
    return x;
}
void solve()
{
    cin >> n;
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        ve.push_back(i);
    } // 还有哪些数字没确认
    vector<ll> tm;
    for (int i = 1; i < n; i++)
    {
        tm.push_back(i);
    } // 还有可能的位置
    ll p = n;
    vector<ll> vis(n + 10, -1);

    for (int i = 0; (1ll << i) <= n && ve.size() > 1; i++)
    {
        ll sum0 = 0;
        ll sum1 = 0;
        for (auto it : ve)
        {
            if (it & (1ll << i))
            {
                sum1++;
            }
            else
            {
                sum0++;
            }
        }
        // //cout << "!!!! " << sum0 << ' ' << sum1 << endl;
        ll s0 = 0, s1 = 0;
        vector<ll> newtm[2];
        for (auto it : tm)
        {
            if (ask(it, (1ll << i)))
            {
                newtm[1].push_back(it);
                vis[it] = i;
                s1++;
            }
            else
            {
                newtm[0].push_back(it);
                s0++;
            }
        }
        // cout << "!!! " << s0 << ' ' << s1 << endl;
        vector<ll> ne;
        if (s1 < sum1)
        {
            tm = newtm[1];
            // 是1
            for (auto it : ve)
            {
                if (it & (1ll << i))
                {
                    ne.push_back(it);
                }
            }
        }
        else
        {
            tm = newtm[0];
            // 是0
            for (auto it : ve)
            {
                if (!(it & (1ll << i)))
                {
                    ne.push_back(it);
                }
            }
        }
        ve = ne;
    }
    cout << "! " << ve[0] << endl;
}
signed main()
{

    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}