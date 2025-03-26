#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 4000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    string s;
    cin >> s;
    ll p1 = 0, p2 = 0;
    stack<ll> st;
    ll sum = 0;
    stack<ll> st2;
    // 未匹配的前缀（
    // 未匹配的后缀 ）
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
            continue;
        }
        if (s[i] == ')')
        {
            if (st.size())
            {
                sum++;
                f[st.top()] = 1;
                f[i] = 1;
                st.pop();
            }
            continue;
        }
    }
    ll q = 0, h = 0;
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0 && s[i] == ')')
        {
            h++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (f[i] == 0 && s[i] == '(')
        {
            q++;
        }
        if (f[i] == 0 && s[i] == ')')
        {
            h--;
        }

        if (s[i] == '?')
        {
            if (q == 0)
            {
                continue;
            }
            if (h == 0)
            {
                continue;
            }
            if (q <= h)
            {
                q--;
                sum++;
            }
            else
            {
                h--;
                sum++;
            }
        }
    }
    cout << sum * 2 << '\n';
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
