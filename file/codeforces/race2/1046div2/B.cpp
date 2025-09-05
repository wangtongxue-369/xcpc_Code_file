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
    ll k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll len = 0;
    ll ml = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '1')
        {
            len++;
        }
        else
        {
            ml = max(ml, len);
            len = 0;
        }
    }
    ml = max(ml, len);
    if ((k == 1 && ml != 0) || ml >= k)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    ll p1 = 1, p2 = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            a[i] = p1;
            p1++;
        }
        else
        {
            a[i] = p2;
            p2--;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        cout << a[i] << ' ';
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