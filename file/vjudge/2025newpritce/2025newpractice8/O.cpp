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
ll _ = 1, n, m, a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN + 10);
vector<ll> du(MAXN + 10, 0);
vector<bool> vis(MAXN + 10, 0);
void solve()
{
    cin >> n;
    ll u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
        du[u]++;
        du[v]++;
    }
    queue<ll> q;
    for (int i = 1; i <= n; i++)
    {
        if (du[i] == 1)
        {
            q.push(i);
            vis[i] = 1;
            break;
        }
    }
    vector<ll> ans;
    while (!q.empty())
    {
        ll p = q.front();
        q.pop();
        ll c;
        for (auto it : ve[p])
        {
            if (vis[it] == 0)
            {
                c = it;
                vis[it] = 1;
                break;
            }
        }
        ans.push_back(ve[c].size());
        for (auto it : ve[c])
        {
            vis[it] = 1;
            for (auto j : ve[it])
            {
                if (vis[j] == 0)
                {
                    q.push(j);
                    vis[p] = 1;
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << ' ';
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
