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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
ll x[MAXN];
void init()
{
    x[0] = 1, x[1] = 1;
    for (int i = 2; i <= 200001; i++)
    {
        if (x[i])
            continue;
        for (int j = i; j <= 200001; j += i)
            x[j] = i;
    }
}
void solve()
{
    cin >> n;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll p = 0;
        ll tmp = a[i];
        ll pr = -1;
        while (tmp > 1)
        {
            if (p != x[tmp])
            {
                ma[x[tmp]]++;
            }
            p = x[tmp];

            tmp /= x[tmp];
        }
    }
    for (auto it : ma)
    {
        if (it.second >= 2)
        {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vector<ll> ve;
        ll p = 0;
        ll tmp = a[i] + 1;
        while (tmp > 1)
        {
            if (p != x[tmp])
            {
                ve.push_back(x[tmp]);
            }
            p = x[tmp];

            tmp /= x[tmp];
        }
        for (auto it : ve)
        {
            if (ma.count(it))
            {
                cout << 1 << '\n';
                return;
            }
        }
    }

    cout << 2 << '\n';
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    init();
    while (_--)
    {
        solve();
    }
    return 0;
}