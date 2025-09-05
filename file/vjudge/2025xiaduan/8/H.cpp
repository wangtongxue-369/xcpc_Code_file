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
    ll q;
    cin >> n >> q;
    set<ll> se;
    vector<ll> su(n + 10);
    for (int i = 0; i <= n; i++)
    {
        se.insert(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > n)
        {
            continue;
        }
        su[a[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (su[i] != 0)
        {
            se.erase(se.find(i));
        }
    }
    while (q--)
    {
        ll p, x;
        cin >> p >> x;
        if (a[p] <= n)
        {
            su[a[p]]--;
            if (su[a[p]] == 0)
            {
                se.insert(a[p]);
            }
        }
        a[p] = x;
        if (a[p] <= n)
        {
            if (su[a[p]] == 0)
            {
                se.erase(a[p]);
            }
            su[a[p]]++;
        }
        cout << *se.begin() << '\n';
    }
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