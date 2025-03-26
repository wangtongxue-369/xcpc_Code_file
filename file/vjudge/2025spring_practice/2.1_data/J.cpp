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
    ll s1, s2;
    vector<PII> ve;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ve.push_back({x, -1});
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ve.push_back({x, 1});
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(ve.begin(), ve.end());
    stack<ll> st;
    vector<ll> p;
    for (auto it : ve)
    {
        if (it.second == -1)
        {
            st.push(it.first);
        }
        else
        {
            p.push_back(it.first - st.top());
            st.pop();
        }
    }
    function<bool(ll, ll)> cmp = [&](ll s1, ll s2)
    {
        return s1 > s2;
    };
    sort(p.begin(), p.end(), cmp);
    ll i = 1;
    sort(a + 1, a + 1 + n);
    ans = 0;
    for (auto it : p)
    {
        ans += it * a[i];
        i++;
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
