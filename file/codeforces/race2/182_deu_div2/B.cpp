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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    priority_queue<ll> q;
    ll sum = 0;
    ll sum0 = 0;
    set<ll> se;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        se.insert(i);
        if (a[i] == 0)
        {
            sum0++;
        }
    }
    if (sum0 == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 0)
            {
                se.erase(a[i]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                a[i] = *se.begin();
            }
        }
    }
    ll l = 1, r = n;
    while (a[l] == l)
    {
        if (l <= r)
        {
            l++;
        }
        else
        {
            break;
        }
    }
    while (a[r] == r)
    {
        if (l <= r)
        {
            r--;
        }
        else
        {
            break;
        }
    }
    cout << r - l + 1 << '\n';
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