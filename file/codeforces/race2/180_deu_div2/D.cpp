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
ll _ = 1, n; // m, ans = 0;// a[MAXN], f[MAXN];
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
    ll tag = 1;
    for (int i = 1; i <= n; i++)
    {
        if (ve[i].size() == 1)
        {
            tag = i;
            break;
        }
    }
    // 首先至少有n-1个对
    // 精确找1个
    bool flag = 0;
    vector<PII> ans;
    function<void(ll x, ll fa, ll p)> dfs = [&](ll x, ll fa, ll p)
    {
        if (ve[x].size() == 2 && flag == 0)
        {
            p = !p;
            flag = 1;
        }
        for (auto it : ve[x])
        {
            if (it == fa)
            {
                continue;
            }
            if (p)
            {
                ans.push_back({x, it});
            }
            else
            {
                ans.push_back({it, x});
            }
            dfs(it, x, !p);
        }
    };
    dfs(tag, 0, 0);
    if (flag)
    {
        cout << "YES\n";
        for (auto it : ans)
        {
            cout << it.first << ' ' << it.second << '\n';
        }
    }
    else
    {
        cout << "NO\n";
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