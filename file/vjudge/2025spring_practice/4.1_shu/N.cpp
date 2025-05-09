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
    ll l, r, v;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> l >> r;
        a[i] = v;
        if (l != 0)
        {
            ve[i].push_back(l);
            ve[l].push_back(i);
        }
        if (r != 0)
        {
            ve[i].push_back(r);
            ve[r].push_back(i);
        }
    }
    ll sum = 0;
    vector<ll> vis(n + 10);
    function<void(ll x, ll d)> dfs = [&](ll x, ll d)
    {
        sum += d * a[x];
        for (auto it : ve[x])
        {
            if (vis[it])
            {
                continue;
            }
            vis[it] = 1;
            dfs(it, d + 1);
        }
    };
    ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vis[j] = 0;
        }
        sum = 0;
        vis[i] = 1;
        dfs(i, 0);
        ans = min(ans, sum);
    }
    cout << ans << '\n';
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