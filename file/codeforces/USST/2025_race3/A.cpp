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
ll c[MAXN], nex[MAXN];
ll find(ll x)
{
    if (a[x] < c[x])
    {
        return x;
    }
    else
    {
        return nex[x] = find(nex[x]);
    }
}
void solve()
{
    ll q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    c[n + 1] = 1e18;
    stack<PII> st;
    st.push({1e18, n + 1});
    for (int i = n; i >= 1; i--)
    {
        while (st.top().first <= c[i])
        {
            st.pop();
        }
        nex[i] = st.top().second;
        st.push({c[i], i});
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << nex[i] << ' ';
    // }
    char cc;
    ll l, x;
    ll p;
    ll tmp;
    while (q--)
    {
        cin >> cc;
        if (cc == '+')
        {
            cin >> l >> x;
            while (x)
            {
                p = find(l);
                tmp = min(x, (c[p] - a[p]));
                a[p] += tmp;
                x -= tmp;
            }
        }
        else
        {
            cin >> l;
            cout << a[l] << '\n';
        }
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