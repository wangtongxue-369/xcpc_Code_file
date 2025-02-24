#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
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
    ll sum = 0;
    ans = 0;
    queue<ll> st;
    ll sum1 = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            if (!st.empty())
            {
                ans += i + 1;
                st.pop();
            }
            else
            {
                ans += i + 1;
            }
        }
        else
        {
            st.push(i + 1);
        }
    }
    ll len = st.size();
    while (!st.empty())
    {
        if (st.size() <= (len + 1) / 2)
        {
            ans += st.front();
        }
        st.pop();
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
