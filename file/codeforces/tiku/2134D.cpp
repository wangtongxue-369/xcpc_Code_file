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
    vector<vector<ll>> ve(n + 10);
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    if (n == 2 || n == 1)
    {
        cout << -1 << '\n';
        return;
    }
    ll c = 0;
    vector<ll> d(n + 10);
    function<void(ll x, ll fa)> dfs = [&](ll x, ll fa)
    {
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            d[it] = d[x] + 1;
            if (d[it] > d[c])
                c = it;
            f[it] = x;
            dfs(it, x);
        }
    };
    dfs(1, 0);
    d[c] = 0;
    // cout << c << '\n';
    f[c] = 0;
    dfs(c, 0);
    // cout << c << '\n';
    // cout << d[c] << '\n';
    vector<ll> t;
    ll p = c;
    while (p)
    {
        t.push_back(p);
        p = f[p];
    }
    set<ll> se;
    for (auto it : t)
    {
        se.insert(it);
        // cout << it << ' ';
    }
    if (d[c] + 1 == n)
    {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < t.size(); i++)
    {
        ll it = t[i];
        if (ve[it].size() >= 3)
        {
            cout << f[it] << ' ' << it << ' ';
            for (auto xx : ve[it])
            {
                if (!se.contains(xx))
                {
                    cout << xx << '\n';
                    return;
                }
            }
        }
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
// ******
// >->>>*
// >>->>>

// 最后至少有三个>>>
// 前面最少有一个>
// 中间至少有一个-
//0 1 2 3 4 5 6 7 

// i位 分解为k
// 修改之后 依然满足原来的要求 bubian
//         不满足 
// dp[i][j] 到第i位被放置到第j个区间最后一个时候的方案数

// 首先尽可能的先找大的分配
// 找到所有每个区间数量对应的k
// 拿map
// 判断每次修改对最小区间数量的改变
// 没变就还是之前
// 变小了 数量+1
// 变大了 数量+2
// 从大变小 数量-1