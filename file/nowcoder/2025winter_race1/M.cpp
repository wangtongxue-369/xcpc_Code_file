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
struct node
{
    ll a;
    ll i;
};
bool cmp(node s1, node s2)
{
    return s1.a < s2.a;
}
void solve()
{
    cin >> n;
    vector<node> p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        node s;
        s.a = a[i], s.i = i;
        p.push_back(s);
    }
    sort(p.begin(), p.end(), cmp);
    p.push_back({(ll)2e9, (ll)2e9});
    ans = 2e9;
    ll l = p[0].i, r = p[0].i;
    ll ma = max(p[0].a * 2, p[n - 1].a);
    ans = ma - min(p[0].a * 2, p[1].a);

    for (int i = 1; i < n; i++)
    {
        while (p[i].i < l)
        {
            l--;
            ma = max(ma, a[l] * 2);
        }
        while (r < p[i].i)
        {
            r++;
            ma = max(ma, a[r] * 2);
        }
        ans = min(ans, ma - min(p[0].a * 2, p[i + 1].a));
    }
    cout << ans << '\n';
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
