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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    s = ' ' + s;
    ll pmi = 1, pma = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < a[pmi])
        {
            pmi = i;
        }
        if (a[i] > a[pma])
        {
            pma = i;
        }
    }
    if (s[1] == '1' || s[n] == '1' || s[pmi] == '1' || s[pma] == '1')
    {
        cout << -1 << '\n';
        return;
    }
    if (pmi < pma)
    {
        cout << 5 << '\n';
        cout << 1 << ' ' << pmi << '\n';
        cout << 1 << ' ' << pma << '\n';
        cout << pma << ' ' << n << '\n';
        cout << pmi << ' ' << n << '\n';
        cout << pmi << ' ' << pma << '\n';
    }
    else
    {
        cout << 5 << '\n';
        cout << 1 << ' ' << pmi << '\n';
        cout << 1 << ' ' << pma << '\n';
        cout << pma << ' ' << n << '\n';
        cout << pmi << ' ' << n << '\n';
        cout << pma << ' ' << pmi << '\n';
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