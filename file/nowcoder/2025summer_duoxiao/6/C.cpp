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
ll get()
{
    stack<ll> st;
    for (int i = 1; i <= n; i++)
    {
        while (!st.empty() && st.top() > a[i])
        {
            st.pop();
        }
        st.push(a[i]);
    }
    return st.size();
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    while (next_permutation(a + 1, a + 1 + n))
    {
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << ' ';
        }
        cout << '\n';
        cout << get() << '\n';
        ;
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