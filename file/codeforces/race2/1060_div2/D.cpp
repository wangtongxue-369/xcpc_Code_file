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
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    vector<ll> dep(n + 10, 0);
    vector<vector<ll>> f(3);
    vector<ll> faa(n + 10);
    vector<ll> siz(n + 10);
    function<void(ll x, ll fa)> dfs = [&](ll x, ll fa)
    {
        // cerr << x << '\n';
        dep[x] = dep[fa] + 1;
        faa[x] = fa;
        if (x != n && ve[x].size() == 1)
        {
            if (x == n)
            {
                cout << "!!!!!!\n";
            }
            siz[x] = 0;
            f[dep[x] % 2].push_back(x);
            return;
        }
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            siz[x]++;
            // cout << it << ' ' << x << '\n';
            dfs(it, x);
        }
    };
    priority_queue<ll> q;
    dfs(n, 0);
    ll p = dep[1] % 2;
    vector<PII> ans;
    for (int i = 1; i < n; i++)
    {
        if (f[!(p % 2)].size() == 0)
        {
            ans.push_back({1, 0});
            p++;
        }
        ll x = f[!(p % 2)].back();
        f[!(p % 2)].pop_back();
        siz[faa[x]]--;
        if (siz[faa[x]] == 0)
        {
            f[p % 2].push_back(faa[x]);
        }
        ans.push_back({2, x});
        ans.push_back({1, 0});
        p++;
    }
    cout << ans.size() << '\n';
    for (auto it : ans)
    {
        if (it.first == 1)
        {
            cout << it.first << '\n';
        }
        else
        {
            cout << it.first << ' ' << it.second << '\n';
        }
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