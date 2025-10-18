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
ll cz(string s, char c)
{
    deque<char> q;
    for (auto it : s)
    {
        if (it == c)
        {
            if (!q.empty())
            {
                q.pop_back();
            }
            else
            {
                q.push_back('X');
            }
        }
        else
        {
            if (!q.empty() && (q.back() == c || q.back() == 'X'))
            {
                q.pop_back();
            }
            else
            {
                q.push_back(c);
            }
        }
    }
    return (ll)q.size();
}
void solve()
{
    string s;
    ll k;
    cin >> n >> k >> s;
    if (k == 0)
    {
        deque<char> q;
        for (auto it : s)
        {
            if (!q.empty() && q.back() == it)
            {
                q.pop_back();
                continue;
            }
            q.push_back(it);
        }
        s.clear();
        while (!q.empty())
        {
            s += q.front();
            q.pop_front();
        }
        cout << s.size() << '\n';
    }
    else if (k >= 2)
    {
        cout << n % 2 << '\n';
    }
    else
    {
        cout << min({cz(s, 'C'), cz(s, 'P'), cz(s, 'J')}) << '\n';
    }
    // 如果两个相同的字符中间是偶数个
    // 有可能可以c
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