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
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    string x;

    ll sum = n;
    for (int i = 0; i < n - m + 1; i++)
    {
        bool flag = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[i + j] == '#')
            {
                continue;
            }
            flag = 1;
            if (s[i + j] != t[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i + j] == '#')
                {
                    continue;
                }
                s[i + j] = '#';
                sum--;
            }
            i -= 5;
            i = max(i, -1);
        }
    }
    if (sum)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
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