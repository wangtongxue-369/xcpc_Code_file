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
    ll p = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        p += (s[i] == '(' ? 1 : -1);
        if (p < 0)
        {
            cout << -1 << '\n';
            return;
        }
    }
    if (p != 0)
    {
        cout << -1 << '\n';
        return;
    }
    stack<char> st;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == '(')
        {

            st.push('(');
            cout << n - st.size() << ' ';
        }
        else
        {
            if (st.empty())
            {
                cout << -1 << '\n';
                return;
            }
            else
            {
                st.pop();
            }
        }
    }
    cout << '\n';
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
