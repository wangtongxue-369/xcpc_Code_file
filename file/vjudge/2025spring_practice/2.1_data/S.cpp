#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll x;
bool check(ll p)
{
    return (n + (n - p + 1)) * p / 2 >= x;
}
ll get()
{
    ll l = 1, r = n + 1;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l - 1;
}
void solve()
{
    string s;
    cin >> s;
    cin >> x;
    deque<ll> q;
    ll p = 1;
    stack<ll> st;
    for (int i = 0; i < s.length(); i++)
    {
        while (st.size() && s[st.top()] > s[i])
        {
            a[st.top()] = p;
            p++;
            st.pop();
        }
        st.push(i);
    }
    while (st.size())
    {
        a[st.top()] = p;
        p++;
        st.pop();
    }
    n = s.length();
    p = get();
    string s1;
    // for (int i = 0; i < s.length(); i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 0; i < s.length(); i++)
    {
        if (a[i] <= p)
        {
            continue;
        }
        else
        {
            s1 += s[i];
        }
    }
    x -= (n + (n - p + 1)) * p / 2;
    // cout << x << ' ' << p << '\n';
    // cout << s1 << '\n';
    cout << s1[x - 1];
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    for (ll i = 1; i <= 1000010; i++)
    {
        f[i] = f[i - 1] + i * (i - 1) / 2;
    }
    while (_--)
    {
        solve();
    }
    return 0;
}
