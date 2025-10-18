/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
#include <bits/stdc++.h>
using namespace std;
#define ll int
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
    vector<vector<ll>> ve(n + 10);
    ll u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<ll> dep(n + 10, 0);
    ll tmd = -1;
    bool flag = 1;
    vector<vector<PII>> co(n + 10);
    map<PII, ll> ma;
    function<void(ll x, ll det, ll fa)> dfs = [&](ll x, ll det, ll fa)
    {
        dep[x] = det;
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            if (dep[it] == 0)
            {
                dfs(it, det + 1, x);
            }
            else
            {
                if (dep[it] > dep[x])
                {
                    continue;
                }
                ll len = dep[x] - dep[it] + 1;
                if (tmd == -1)
                {
                    tmd = len;
                }
                if (tmd != len)
                {
                    flag = 0;
                    return;
                }
                co[x].push_back({x, it});
            }
        }
        if (flag == 0)
        {
            return;
        }
        for (auto it : co[x])
        {
            for (auto i : co[x])
            {
                if (!ma[{it.first, i.first}])
                {
                    ma[{it.first, i.first}] = x;
                }
            }
        }
        for (auto it : co[x])
        {
            if (it.second == fa)
            {
                continue;
            }
            ll cnt = 0;
            for (auto p : co[fa])
            {
                if (p.second == it.second && dep[p.first] == dep[it.first] && tmd % 2 == 0 && dep[fa] - dep[p.second] == tmd / 2)
                    cnt++;
            }
            if (cnt <= 1)
            {
                co[fa].push_back(it);
            }
        }
        for (int i = 0; i < co[x].size(); i++)
        {
            for (int j = i + 1; j < co[x].size(); j++)
            {
                if (tmd % 2 == 1 || dep[ma[{co[x][i].first, co[x][j].first}]] - max(dep[co[x][i].second], dep[co[x][j].second]) != tmd / 2)
                {
                    flag = false;
                    return;
                }
            }
        }
    };
    dfs(1, 1, 0);
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
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