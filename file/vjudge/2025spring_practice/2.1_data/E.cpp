#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned int
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ull _ = 1, n, m, a[MAXN], f[MAXN];
ull p, q;
ull sa, sb, sc;
ll p1;
ull rng61()
{
    sa ^= sa << 16;
    sa ^= sa >> 5;
    sa ^= sa << 1;
    ull t = sa;
    sa = sb;
    sb = sc;
    sc ^= t ^ sa;
    return sc;
}
void solve()
{
    cin >> n >> p >> q >> m >> sa >> sb >> sc;
    vector<ull> maxn(n + 10, 0);
    stack<ull> st;
    ll ans = 0;
    for (ll i = 1; i <= n; i++)
    {
        if ((rng61() % (q + p)) < p)
        {
            ull x = rng61() % m + 1;
            maxn[st.size() + 1] = 0;
            st.push(x);
            maxn[st.size()] = max(maxn[st.size() - 1], x);
            // push();
        }
        else
        {
            if (st.size())
            {
                st.pop();
            }
        }
        ans ^= (i * maxn[st.size()]);
    }
    cout << "Case #" << p1 << ": " << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    for (p1 = 1; p1 <= _; p1++)
    {
        solve();
    }
    return 0;
}
