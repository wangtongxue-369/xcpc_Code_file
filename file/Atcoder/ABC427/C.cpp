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
    cin >> n >> m;
    vector<vector<ll>> ve(n + 10);
    vector<PII> b;
    ll u, v;
    map<PII, ll> ma;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        ma[{u, v}] = 1;
        ma[{v, u}] = 1;
        ve[u].push_back(v);
        ve[v].push_back(u);
        b.push_back({u, v});
    }
    ans = m;
    for (int i = 0; i < (1ll << n); i++)
    {
        ll sum = 0;
        vector<ll> col(n + 10);
        for (int j = 0; j < n; j++)
        {
            if ((1ll << j) & i)
            {
                col[j + 1] = 1;
            }
        }
        for (auto it : b)
        {
            if (col[it.first] == col[it.second])
            {
                sum++;
            }
        }
        ans = min(ans, sum);
    }
    cout << ans << '\n';
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