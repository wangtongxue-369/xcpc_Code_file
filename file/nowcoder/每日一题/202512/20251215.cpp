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
#define ld long double
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
    vector<vector<ll>> ve(s.length() + 10, vector<ll>(26, -1));
    vector<ll> fi(30, -1);
    for (int i = 0; i < s.length(); i++)
    {
        if (fi[s[i] - 'a'] == -1)
        {
            fi[s[i] - 'a'] = i;
        }
    }
    for (int i = s.length() - 1 - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (j == s[i + 1] - 'a')
            {
                ve[i][j] = i + 1;
                continue;
            }
            if (ve[i + 1][j] == -1)
            {
                continue;
            }
            else
            {
                ve[i][j] = ve[i + 1][j];
            }
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {
        string ss;
        cin >> ss;
        bool flag = 1;
        ll p = fi[ss[0] - 'a'];
        for (int i = 1; i < ss.length(); i++)
        {
            if (p == -1)
            {
                flag = 0;
                break;
            }
            p = ve[p][ss[i] - 'a'];
        }
        if (p == -1)
        {
            flag = 0;
        }
        if (flag)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
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