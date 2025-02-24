#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, m, ans = 0, a[MAXN], f[MAXN];
void dfs(ll n)
{
    if (n == 0)
    {
        cout << 0;
        return;
    }
    stack<ll> st;
    ll i = 0;
    while (n)
    {
        if (n % 2 == 1)
        {
            st.push(i);
        }
        i++;
        n >>= 1;
    }
    while (!st.empty())
    {
        ll x = st.top();
        st.pop();
        if (x == 1)
        {
            cout << 2;
        }
        else
        {
            cout << "2(";
            dfs(x);
            cout << ")";
        }
        if (!st.empty())
        {
            cout << '+';
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    dfs(n);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
