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
    bool flag = 1;
    stack<char> st;
    for (auto it : s)
    {
        if (it == ')')
        {
            if (st.size() == 0 || st.top() != '(')
            {
                flag = 0;
                break;
            }
            else
            {
                st.pop();
            }
        }
        else if (it == '(')
        {
            st.push('(');
        }
        else if (it == ']')
        {
            if (st.size() == 0 || st.top() != '[')
            {
                flag = 0;
                break;
            }
            else
            {
                st.pop();
            }
        }
        else if (it == '[')
        {
            st.push('[');
        }
    }
    if (st.size())
    {
        flag = 0;
    }
    if (flag)
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
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