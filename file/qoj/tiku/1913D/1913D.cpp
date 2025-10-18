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
    string s;
    cin >> s;
    s = " " + s;
    ll st = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
        {
            st++;
        }
        else
        {
            break;
        }
    }
    if (s[n] == '0' && s[n - 1] == '0')
    {
        cout << "Yes\n";
        return;
    }
    ll en = n - 2;
    if (s[n] == '1' && s[n - 1] == '0')
    {
        en = n - 1;
    }
    if (s[en] == '1')
    {
        en--;
        if (s[en] == '1')
        {
            en--;
        }
    }
    if (en == n - 4)
    {
        cout << "Yes\n";
        return;
    }
    ll cnt1 = 0, cnt0 = 0;
    for (int i = en; i >= st; i--)
    {
        if (s[i] == '1')
        {
            cnt1++;
        }
        else
        {
            cnt0++;
        }
        if (i != n - 2 && cnt1 >= cnt0)
        {
            cout << "Yes\n";
            return;
        }
    }
    if (cnt1 - 1 >= cnt0 + 1 || cnt1 - 2 >= cnt0 + 2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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