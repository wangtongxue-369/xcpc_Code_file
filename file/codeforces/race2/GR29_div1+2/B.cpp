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
    cin >> n;
    ll p = n;
    vector<ll> a(2 * n + 10);
    a[1] = p, a[n + 1] = p;
    p--;
    for (int i = 2; i <= n; i += 1)
    {
        a[i] = p, a[2 * n - i + 1 + 1] = p;
        p--;
    }
    map<ll, vector<ll>> ma;
    for (int i = 1; i <= 2 * n; i++)
    {
        ma[a[i]].push_back(i);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     if (ma[i].size() != 2)
    //     {
    //         cout << "!!!\n";
    //         return;
    //     }
    //     else
    //     {
    //         if (abs(ma[i][1] - ma[i][0]) % i != 0)
    //         {
    //             cout << "!!!" << '\n';
    //             return;
    //         }
    //     }
    // }
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << a[i] << " ";
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