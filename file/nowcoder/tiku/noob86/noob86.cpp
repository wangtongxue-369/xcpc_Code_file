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
    string ans;
    for (auto it : s)
    {
        if (it == 'o')
        {
            if (ans.size() && ans.back() == 'o')
            {
                ans.pop_back();
                ans += 'O';
            }
            else
            {
                ans += 'o';
            }
        }
        else if (it == 'O')
        {
            if (ans.size() && ans.back() == 'O')
            {
                ans.pop_back();
            }
            else
            {
                ans += 'O';
            }
        }
        bool flag = 1;
        while (flag)
        {
            if (ans.size() < 2)
            {
                flag = 0;
                continue;
            }
            flag = 0;
            if (ans[ans.length() - 1] == 'o' && ans[ans.length() - 2] == 'o')
            {
                ans.pop_back();
                ans.pop_back();
                ans.push_back('O');
                flag = 1;
            }
            else if (ans[ans.length() - 1] == 'O' && ans[ans.length() - 2] == 'O')
            {
                ans.pop_back();
                ans.pop_back();
                flag = 1;
            }
        }
    }
    cout << ans << '\n';
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