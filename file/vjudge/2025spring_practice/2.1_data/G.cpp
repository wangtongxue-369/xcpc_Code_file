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
    stack<ll> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ']')
        {
            if (st.size())
            {
                if (s[st.top()] == '[')
                {
                    f[st.top()] = 1;
                    f[i] = 1;
                    st.pop();
                }
            }
            continue;
        }
        if (s[i] == ')')
        {
            if (st.size())
            {
                if (s[st.top()] == '(')
                {
                    f[st.top()] = 1;
                    f[i] = 1;
                    st.pop();
                }
            }
            continue;
        }
        st.push(i);
    }
    // for (int i = 0; i < s.length(); i++)
    // {
    //     cout << f[i];
    // }
    for (int i = 0; i < s.length(); i++)
    {
        if (f[i] == 1)
        {
            cout << s[i];
            continue;
        }
        if (s[i] == '(')
        {
            cout << s[i] << ')';
        }
        if (s[i] == ')')
        {
            cout << '(' << s[i];
        }
        if (s[i] == ']')
        {
            cout << '[' << s[i];
        }
        if (s[i] == '[')
        {
            cout << s[i] << ']';
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
