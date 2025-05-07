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
void solve()
{

    ll u, v;
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    vector<ll> f(n + 10);
    vector<ll> vis(n + 10, 0);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    function<ll(ll x)> dfs = [&](ll x)
    {
        bool flag = 1;
        ll res = 0, tm = 0;
        for (auto it : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            flag = 0;
            vis[it] = 1;
            f[it] = dfs(it);
            res += f[it];
        }
        if (flag)
        {
            return (ll)1;
        }
        return res;
    };
    vis[1] = 1;
    f[1] = dfs(1);
    ll q;
    cin >> q;
    ll x, y;
    while (q--)
    {
        cin >> x >> y;
        cout << f[x] * f[y] << '\n';
    }
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