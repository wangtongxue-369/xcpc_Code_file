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
    string s;
    cin >> s;
    bool flag = 1;
    for (int i = 0; i < (ll)s.length() - 2; i++)
    {
        if ((s[i] == 'F' && s[i + 1] == 'F' && s[i + 2] == 'T') || (s[i] == 'N' && s[i + 1] == 'T' && s[i + 2] == 'T'))
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << s << '\n';
        return;
    }
    ll sumn = 0, sumt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'N')
        {
            sumn++;
        }
        if (s[i] == 'T')
        {
            sumt++;
        }
    }
    while (sumt--)
    {
        cout << 'T';
    }
    while (sumn--)
    {
        cout << 'N';
    }
    for (auto it : s)
    {
        if (it == 'T' || it == 'N')
        {
            continue;
        }
        cout << it;
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