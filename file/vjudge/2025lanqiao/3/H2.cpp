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
    ll a = 0;
    ll s = 0;
};
vector<node> ve;
bool cmp(node s1, node s2)
{
    if (s1.a == s2.a)
    {
        return s1.s > s2.s;
    }
    return s1.a < s2.a;
}
ll i;
ll ff(ll x)
{
    ll l = 0, r = ve.size() - 1;
    if (ve.size() == 0)
    {
        return -1;
    }
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (ve[mid].a <= x)
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (ve[l].a == x)
    {
        return l;
    }
    else
    {
        return -1;
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (i = 1; i <= n; i++)
    {
        ll it = ff(a[i] - 1);
        if (it == -1)
        {
            ve.push_back({a[i], 1});
            continue;
        }
        else
        {
            ve[it].a++, ve[it].s++;
            sort(ve.begin(), ve.end(), cmp);
        }
    }
    ans = 1e10;
    for (auto it : ve)
    {
        ans = min(ans, it.s);
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