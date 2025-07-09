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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
void solve()
{
    cin >> n >> m;
    vector<vector<PII>> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll s, t, w;
    ll maxn = 0;
    for (int i = 1; i <= m; i++)
    {
        cin >> s >> t >> w;
        ve[s].push_back({t, w});
        maxn = max(maxn, w);
    }
    auto check = [&](ll x)
    {
        vector<ll> vis(n + 10, -1);
        vis[1] = b[1];
        if (vis[1] > x)
        {
            vis[1] = x;
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] < 0)
            {
                continue;
            }
            for (auto [v, w] : ve[i])
            {
                if (w <= x && vis[i] >= w)
                {
                    ll nex = vis[i] + b[v];
                    if (nex > vis[v])
                    {
                        vis[v] = nex;
                    }
                    if (vis[v] > x)
                    {
                        vis[v] = x;
                    }
                }
            }
        }
        if (vis[n] != -1)
        {
            return 1;
        }
        return 0;
    };
    ll l = 0, r = maxn;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (check(l))
    {
        cout << l << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}
// 走过的路的边权的最大值就是电池数量

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