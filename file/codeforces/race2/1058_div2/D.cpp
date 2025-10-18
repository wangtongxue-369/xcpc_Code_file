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
ll ask(vector<ll> ve)
{
    cout << "? " << ve.size() << ' ';
    for (auto it : ve)
    {
        cout << it << ' ';
    }
    cout << endl;
    ll x;
    cin >> x;
    return x;
}
void solve()
{
    cin >> n;
    vector<ll> ve;
    vector<ll> a(2 * n + 10);
    vector<ll> re;
    for (int i = 1; i <= 2 * n; i++)
    {
        ve.push_back(i);
        ll x = ask(ve);
        if (x)
        {
            a[i] = x;
            re.push_back(i);
            ve.pop_back();
        }
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (a[i] == 0)
        {
            re.push_back(i);
            ll x = ask(re);
            a[i] = x;
            re.pop_back();
        }
    }

    cout << "! ";
    for (int i = 1; i <= 2 * n; i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
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