#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
vector<vector<ll>> ve(MAXN + 10);
ll dfs(ll i, ll fa)
{
    ll sum = 1;
    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        ll tmp = dfs(it, i);
        sum += tmp;
    }
    if (sum % 2 == 0 && sum != 0)
    {
        // cout << i << ' ' << sum << '\n';
        ans++;
    }
    return sum;
}
void solve()
{
    cin >> n;
    ll u, v;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    // cout << '!' << '\n';
    if (n % 2 == 1)
    {
        cout << -1 << '\n';
        return;
    }
    ll tmp = dfs(1, -1);
    cout << --ans << '\n';
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
