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
ll get(ll x)
{
    string s = to_string(x);
    reverse(s.begin(), s.end());
    ll p = 0;
    for (int i = 0; i < s.length(); i++)
    {
        p = i;
        if (s[i] != '0')
        {
            break;
        }
    }
    string t;
    x = 0;
    for (int i = p; i < s.length(); i++)
    {
        x = x * 10 + s[i] - '0';
    }
    return x;
}
void solve()
{
    ll x, y;
    cin >> x >> y;
    n = 10;
    vector<ll> ve;
    ve.push_back(x);
    ve.push_back(y);
    for (int i = 2; i < 10; i++)
    {
        ve.push_back(get(ve[i - 1] + ve[i - 2]));
    }
    cout << ve[9];
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