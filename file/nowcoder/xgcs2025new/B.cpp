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
    string s;
    cin >> s;
    bool flag = 0;
    ll pos = 0;
    for (int i = 0; i < s.length(); i++)
    {
        auto it = s[i];
        if (it == '.')
        {
            flag = 1;
            pos = i;
        }
    }
    if (flag == 0)
    {
        cout << s << '\n';
        return;
    }
    if ((s[pos + 1] - '0') >= 5)
    {
        bool is = 1;
        for (int i = pos - 1; i >= 0 && is; i--)
        {
            ll p = s[i] - '0' + is;
            s[i] = char(p % 10 + '0');
            is = p / 10;
        }
        if (is)
        {
            cout << 1;
        }
        for (int i = 0; i < pos; i++)
        {
            cout << s[i];
        }
        cout << '\n';
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            cout << s[i];
        }
        cout << '\n';
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