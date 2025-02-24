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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], k;
stack<ll> st;
void dfs(ll x)
{
    if (x == k)
    {
        stack<ll> s;
        while (!st.empty())
        {
            s.push(st.top());
            st.pop();
        }
        while (!s.empty())
        {
            cout << s.top() << ' ';
            st.push(s.top());
            s.pop();
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 0)
        {
            st.push(i);
            a[i] = 1;
            dfs(x + 1);
            a[i] = 0;
            st.pop();
        }
    }
}
void solve()
{
    cin >> n >> k;
    dfs(0);
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
