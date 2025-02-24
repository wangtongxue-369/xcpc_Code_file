#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 200005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
struct node
{
    ll i;
    ll w;
};
vector<vector<node>> ve(MAXN + 100);
void dfs(ll i, ll sum, ll fa)
{
    a[i] = sum;
    for (auto it : ve[i])
    {
        if (it.i == fa)
        {
            continue;
        }
        dfs(it.i, a[i] ^ it.w, i);
    }
}
void solve()
{
    cin >> n;
    ll u, v, w;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v >> w;
        ve[u].push_back({v, w});
        ve[v].push_back({u, w});
    }
    dfs(1, 0, -1);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    ans = 0;
    for (int i = 62; i >= 0; i--)
    {
        ll cnt0 = 0, cnt1 = 0;
        for (int j = 1; j <= n; j++)
        {
            if ((a[j] >> i) & 1 == 1)
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }
        ll tmp = (cnt1 * cnt0) % mod;
        tmp = (tmp * ((1ll << i) % mod) % mod);
        ans = (ans + tmp) % mod;
        // ans = (ans + ((((cnt1 * cnt0) % mod) * (1ll << i) % mod)) % mod) % mod;
    }
    cout << ans << '\n';
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
