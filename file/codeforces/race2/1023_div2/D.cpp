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
ll _ = 1, n, m;
void solve()
{
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<ll> f(n + 10, 0);
    vector<ll> vis(n + 10, 0); // se(n + 10, 0);
    vector<array<ll, 3>> ans;
    while (1)
    {
        bool flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            break;
        }
        vector<ll> se(n + 10, 0);
        function<PII(ll x, ll fa, ll dep)> dfs = [&](ll x, ll fa, ll dep)
        {
            PII res = {dep, x};
            f[x] = fa;
            se[x] = 1;
            for (auto it : ve[x])
            {
                if (it == fa || vis[it])
                {
                    continue;
                }
                PII t = dfs(it, x, dep + 1);
                res = max(res, t);
            }
            return res;
        };
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] != 0 || se[i] != 0)
            {
                continue;
            }
            PII r1 = dfs(i, -1, 1);
            PII r2 = dfs(r1.second, -1, 1);
            ans.push_back({r2.first, max(r1.second, r2.second), min(r1.second, r2.second)});
            ll p = r2.second;
            // cout << r1.second << ' ' << r2.second << '\n';

            while (p != -1)
            {
                vis[p] = 1;
                p = f[p];
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<array<ll, 3>>());
    for (auto it : ans)
    {
        cout << it[0] << ' ' << it[1] << ' ' << it[2] << ' ';
    }
    cout << '\n';
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