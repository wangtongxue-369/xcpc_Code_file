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
ll _ = 1; // n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].emplace_back(v);
        ve[v].emplace_back(u);
    }
    vector<ll> ans(n + 10, 0);
    ll p = 1;
    auto dfs = [&](auto &&self, ll i, ll fa) -> void
    {
        bool flag = 0;
        for (auto it : ve[i])
        {
            if (it == fa)
            {
                continue;
            }
            if (!flag)
            {
                flag = 1;
                p++;
                ans[it] = p;
                self(self, it, i);
                p++;
            }
            else
            {
                p += 2;
                ans[it] = p;
                self(self, it, i);
            }
        }
    };
    ans[1] = 1;
    dfs(dfs, 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
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
