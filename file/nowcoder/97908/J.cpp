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
ll _ = 1, n, m, ans = INF, t[MAXN]; // f[MAXN];
vector<vector<PII>> ve(MAXN + 10);
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= m; i++)
    {
        ll u, v, x;
        cin >> u >> v >> x;
        ve[u].push_back({v, x});
        ve[v].push_back({u, x});
    }
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});
    vector<ll> mint(MAXN + 10, 1e18);
    mint[1] = 0, mint[0] = 0;
    bool flag = 0;
    while (!q.empty())
    {
        auto [w, i] = q.top();
        q.pop();
        if (w >= t[i])
        {
            continue;
        }
        if (i == n)
        {
            cout << "YES\n"
                 << w << '\n';
            return;
        }
        for (auto [it, x] : ve[i])
        {
            ll tw = w + x;
            if (tw < mint[it] && tw < t[it])
            {
                mint[it] = tw;
                q.push({tw, it});
            }
        }
    }
    cout << "NO\n";
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