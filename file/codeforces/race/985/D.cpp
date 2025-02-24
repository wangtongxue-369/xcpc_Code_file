#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m; // ans = 0; // a[MAXN], f[MAXN];

void solve()
{
    cin >> n >> m;
    ll u, v;
    vector<set<ll>> ve(n + 100);
    for (int i = 1; i <= n; i++)
    {
        ve[i].clear();
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ve[u].insert(v);
        ve[v].insert(u);
    }
    queue<vector<ll>> ans;
    for (int i = 1; i <= n; i++)
    {
        while (ve[i].size() >= 2)
        {
            ll s1 = *ve[i].begin();
            ve[i].erase(ve[i].begin());
            ll s2 = *ve[i].begin();
            ve[i].erase(ve[i].begin());
            ve[s1].erase(i);
            ve[s2].erase(i);
            if (ve[s1].find(s2) != ve[s1].end())
            {
                ve[s1].erase(s2);
                ve[s2].erase(s1);
            }
            else
            {
                ve[s1].insert(s2);
                ve[s2].insert(s1);
            }
            ans.push({s1, s2, i});
        }
    }
    vector<ll> ve1;
    for (int i = 1; i <= n; i++)
    {
        if (ve[i].size() == 0)
        {
            ve1.push_back(i);
        }
    }
    if (ve1.size() != n)
    {
        ll u, v;
        vector<ll> vv(n + 100, 0);
        for (int i = 1; i <= n; i++)
        {
            if (ve[i].size() == 0)
            {
                continue;
            }
            else
            {
                u = i;
                vv[i] = 1;
                vv[*ve[i].begin()] = 1;
                v = *ve[i].begin();
                break;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (vv[i] == 1)
            {
                continue;
            }
            if (ve[i].size() == 0)
            {
                ans.push({u, v, i});
                v = v;
                u = i;
                vv[i] = 1;
            }
            else
            {
                vv[i] = 1;
                vv[*ve[i].begin()] = 1;
                ans.push({v, *ve[i].begin(), i});
            }
        }
    }
    cout << ans.size() << '\n';
    while (!ans.empty())
    {
        auto i = ans.front();
        ans.pop();
        for (auto it : i)
        {
            cout << it << ' ';
        }
        cout << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
