/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#pragma GCC optimize(2)

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
    cin >> n >> m;
    ll u, v, w;
    vector<vector<PII>> ve(n + 10);
    vector<PII> tu(m + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> tu[i].first >> tu[i].second;
    }
    vector<ll> dis(n + 10);
    function<void(ll x, ll fa, ll sum)> dfs = [&](ll x, ll fa, ll sum)
    {
        dis[x] = sum;
        for (auto it : ve[x])
        {
            if (it.first == fa)
            {
                continue;
            }
            dfs(it.first, x, sum + it.second);
        }
    };
    dfs(1, 0, 0);
    vector<ll> lst = dis;
    ll sum = 0;
    ll psum;
    for (int i = 1; i <= n; i++)
    {
        sum += dis[i];
        // cout << dis[i] << ' ';
    }

    cout << sum << '\n';
    psum = sum;
    for (int k = 1; k <= n; k++)
    {
        lst = dis;
        queue<ll> q;
        for (int i = 1; i <= m; i++)
        {
            u = tu[i].first, v = tu[i].second;
            dis[u] = min(dis[u], lst[v]);
            dis[v] = min(dis[v], lst[u]);
            q.push(u);
            q.push(v);
        }
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            for (auto [v, w] : ve[x])
            {
                if (dis[v] > dis[x] + w)
                {
                    dis[v] = dis[x] + w;
                    q.push(v);
                }
            }
        }
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += dis[i];
            // cout << dis[i] << ' ';
        }
        cout << sum << "\n";
        if (psum == sum)
        {
            while (k <= n)
            {
                cout << sum << ' ';
                k++;
            }
        }
    }
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