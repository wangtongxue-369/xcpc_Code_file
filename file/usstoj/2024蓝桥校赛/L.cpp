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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
struct node
{
    ll v, i;
} a[MAXN + 10];
vector<vector<ll>> ve(MAXN + 10);
vector<bool> f(MAXN + 10, 0);
vector<ll> val(MAXN + 10, 0);
bool cmp(node s1, node s2)
{
    return s1.v > s2.v;
}
void dfs(ll i, ll v)
{
    val[i] = v;
    for (auto it : ve[i])
    {
        if (f[it] == 1)
        {
            continue;
        }
        f[it] = 1;
        dfs(it, v);
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        a[i].i = i;
    }
    sort(a + 1, a + 1 + n, cmp);
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[a[i].i] == 1)
        {
            continue;
        }
        f[a[i].i] = 1;
        dfs(a[i].i, a[i].v);
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += val[i];
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
