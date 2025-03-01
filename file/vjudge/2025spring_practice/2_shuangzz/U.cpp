#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[110], f[1 << 20];
ll vis[1 << 20];
ll w[] = {0, 3, 4, 5, 4, 3};
vector<vector<PII>> ve(100);
// jeizhu i cong dao
void init()
{
    ve[1].emplace_back(0, 2);
    ve[3].emplace_back(0, 7);
    ve[4].emplace_back(0, 9), ve[4].emplace_back(1, 8), ve[4].emplace_back(3, 5);
    ve[5].emplace_back(1, 10), ve[5].emplace_back(2, 9), ve[5].emplace_back(4, 6);
    ve[6].emplace_back(2, 11);
    ve[8].emplace_back(3, 13), ve[8].emplace_back(4, 12), ve[8].emplace_back(7, 9);
    ve[9].emplace_back(4, 14), ve[9].emplace_back(5, 13), ve[9].emplace_back(8, 10);
    ve[10].emplace_back(5, 15), ve[10].emplace_back(6, 14), ve[10].emplace_back(9, 11);
    ve[12].emplace_back(7, 16);
    ve[13].emplace_back(8, 17), ve[13].emplace_back(9, 16), ve[13].emplace_back(12, 14);
    ve[14].emplace_back(9, 18), ve[14].emplace_back(10, 17), ve[14].emplace_back(13, 15);
    ve[15].emplace_back(11, 18);
    ve[17].emplace_back(16, 18);
    ve[1].emplace_back(2, 0);
    ve[3].emplace_back(7, 0);
    ve[4].emplace_back(9, 0), ve[4].emplace_back(8, 1), ve[4].emplace_back(5, 3);
    ve[5].emplace_back(10, 1), ve[5].emplace_back(9, 2), ve[5].emplace_back(6, 4);
    ve[6].emplace_back(11, 2);
    ve[8].emplace_back(13, 3), ve[8].emplace_back(12, 4), ve[8].emplace_back(9, 7);
    ve[9].emplace_back(14, 4), ve[9].emplace_back(13, 5), ve[9].emplace_back(10, 8);
    ve[10].emplace_back(15, 5), ve[10].emplace_back(14, 6), ve[10].emplace_back(11, 9);
    ve[12].emplace_back(16, 7);
    ve[13].emplace_back(17, 8), ve[13].emplace_back(16, 9), ve[13].emplace_back(14, 12);
    ve[14].emplace_back(18, 9), ve[14].emplace_back(17, 10), ve[14].emplace_back(15, 13);
    ve[15].emplace_back(18, 11);
    ve[17].emplace_back(18, 16);
}
ll dfs(ll now)
{
    if (vis[now])
    {
        return f[now];
    }
    for (int i = 0; i < 19; i++)
    {
        if ((now & (1ll << i)))
        {
            f[now] = max(f[now], dfs(now - (1ll << i)));
        }
    }
    for (int i = 0; i < 19; i++)
    {
        if ((now & (1ll << i)))
        {
            for (auto it : ve[i])
            {
                if (((now & (1ll << it.first))) && (!(now & (1ll << it.second))))
                {
                    f[now] = max(f[now], dfs(now - (1ll << it.first) - (1ll << i) + (1ll << it.second)) + a[i]);
                }
            }
        }
    }
    vis[now] = 1;
    return f[now];
}
void solve()
{
    init();
    n = 19;
    f[0] = 0, vis[0] = 1;
    for (int i = 0; i < 19; i++)
    {
        cin >> a[i];
    }
    ll t;
    cin >> t;
    while (t--)
    {
        ll x = 0;
        char c;
        for (ll i = 0; i < 19; i++)
        {
            cin >> c;
            if (c == '#')
            {
                x += (1ll << i);
            }
        }
        // cout << x << '\n';
        cout << dfs(x) << '\n';
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
