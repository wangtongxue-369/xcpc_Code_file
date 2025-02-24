#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 100005;
ll _ = 1, n, m; // ans = 0;// a[500005], f[500005];
struct node
{
    ll w, i;
    string s;
} a[N];
bool cmp(node s1, node s2)
{
    return s1.w > s2.w;
}
void solve()
{
    ll k, c = 1e9;
    cin >> n >> k;
    ll s;
    vector<ll> ans(n + 10);
    map<string, ll> ma;
    for (int i = 1; i <= k; i++)
    {
        cin >> s;
        c = min(c, s);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i].i = i;
        cin >> a[i].w >> a[i].s;
        ma[a[i].s]++;
    }
    map<string, ll> now;
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        now[a[i].s]++;
        ans[a[i].i] = max(ma[a[i].s] - now[a[i].s] + c, 1ll);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
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
