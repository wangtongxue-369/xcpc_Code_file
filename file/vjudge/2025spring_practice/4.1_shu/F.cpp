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
    ll u, v;
    vector<vector<PII>> ve(n + 10);
    vector<ll> dp(n + 10), d(n + 10);
    vector<ll> vis(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back({v, i});
        ve[v].push_back({u, i});
    }
    dp[1] = 1;
    d[1] = 0;
    vis[1] = 1;
    function<void(ll x)> dfs = [&](ll x)
    {
        for (auto it : ve[x])
        {
            if (vis[it.first])
            {
                continue;
            }
            vis[it.first] = 1;
            if (it.second <= d[x])
            {
                dp[it.first] = dp[x] + 1;
            }
            else
            {
                dp[it.first] = dp[x];
            }
            d[it.first] = it.second;
            dfs(it.first);
        }
    };
    dfs(1);
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
    // cout << q.top().first << '\n';
    // vis[1] = 1;
    // ans = 0;
    // //ok 自己连接的有几个画过了
    // for (auto it : ve[1])
    // {
    //     ok[it]++;
    // }
    // while (!q.empty())
    // {
    //     ans++;
    //     vector<PII> tmp;
    //     for (auto it : q)
    //     {
    //         auto [i, x] = it;
    //         if (ok[x] == tot[x])
    //         {
    //             continue;
    //         }
    //         if (ok[x] == 0)
    //         {
    //             tmp.push_back({i, x});
    //             continue;
    //         }
    //         for (auto it : ve[x])
    //         {
    //             if (vis[it])
    //             {
    //                 continue;
    //             }
    //             vis[it] = 1;
    //             ok[x]++;
    //             ok[it]++;
    //             if (ok[x] == tot[x])
    //             {
    //             }
    //             else
    //             {
    //                 tmp.push_back({i, x});
    //             }
    //             break;
    //         }
    //     }
    //     cerr << tmp.size() << '\n';
    //     q = tmp;
    //     cerr << "!!!\n";
    //     for (auto it : q)
    //     {
    //         cerr << it.first << ' ' << it.second << "     ";
    //     }
    //     cerr << '\n';
    // }
    // cout << ans << '\n';

    // function<void(ll x)> dfs = [&](ll x)
    // {
    //     bool flag = 0;
    //     for (auto it : ve[x])
    //     {
    //         if (vis[it])
    //         {
    //             continue;
    //         }
    //         flag = 1;
    //         vis[it] = 1;
    //         dfs(it);
    //     }
    //     ans += (ll)flag;
    // };
    // vis[1] = 1;
    // dfs(1);
    // cout << ans - 1 << '\n';
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