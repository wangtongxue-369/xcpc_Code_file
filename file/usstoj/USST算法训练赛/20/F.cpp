#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
vector<vector<ll>> tree(MAXN + 10);
ll dfs(ll i, ll dep)
{
    if (tree[i].size() == 0)
    {
        return dep;
    }
    for (auto it : tree[i])
    {
        dep = max(dep, dfs(it, dep + 1));
    }
    return dep;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        // tree[v].push_back(u);
        tree[u].push_back(v);
    }
    ll A = dfs(1, 1);
    ll B = dfs(2, 1);
    if (A == B)
    {
        cout << "You are my brother\n";
    }
    else if (A < B)
    {
        cout << "You are my younger\n";
    }
    else if (A > B)
    {
        cout << "You are my elder\n";
    }
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
