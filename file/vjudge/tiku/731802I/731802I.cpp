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
ll _ = 1, n, m, ans = 0, a[MAXN], ru[MAXN];
double f[MAXN], g[MAXN];
void solve()
{
    ans = 0;
    cin >> n >> m;
    queue<ll> q;
    vector<vector<PII>> ve(n + 10);
    ll u, v, w;

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ru[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ru[i] == 0)
        {
            q.push(i);
        }
    }
    g[1] = 1;
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        double du = ve[x].size();
        for (auto [it, w] : ve[x])
        {
            f[it] += (1.0 * f[x] + 1.0 * g[x] * w) / du;
            ru[it]--;
            g[it] += 1.0 * g[x] / du;
            if (ru[it] == 0)
            {
                q.push(it);
            }
        }
    }
    cout << fixed << setprecision(2) << f[n] << '\n';
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