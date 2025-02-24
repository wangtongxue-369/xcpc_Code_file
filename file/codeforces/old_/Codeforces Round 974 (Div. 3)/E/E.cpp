#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const ll mod = 1e9 + 7;
const ll N = 200005;
ll _ = 1, n, m, h, ans = 0, a[500005]; // f[500005];
struct node
{

    ll i, d;
};
vector<vector<node>> ve(N + 10);
void solve()
{
    cin >> n >> m >> h;
    for (int i = 1; i <= h; i++)
    {
        cin >> a[i];
    }
    ll u, v, w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
