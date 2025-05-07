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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    map<PII, ll> ma;
    vector<vector<ll>> ve(n + 1);
    ll u, v, p, q;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v >> p >> q;
        ve[u].push_back(v);
        ve[v].push_back(u);
        ma[{u, v}] = p;
        ma[{v, u}] = q;
    }
    ll s, t;
    cin >> s >> t;
    auto dfs = [&](auto &&self, ll u, ll fa) -> pair<ll, bool>
    {
        pair<ll, bool> res{0, false};
        for (auto &v : ve[u])
        {
            if (v == fa)
            {
                continue;
            }
            auto [tmp, is] = self(self, v, u);
            if (tmp > 0 || is)
            {
                res.first += tmp;
            }
            if (is)
            {
                res.second = 1;
            }
        }
        if (u == t)
        {
            res.second = true;
        }
        if (res.second)
        {
            res.first += ma[{fa, u}];
        }
        else
        {
            res.first += ma[{fa, u}] + ma[{u, fa}];
        }
        return res;
    };
    auto [x, y] = dfs(dfs, s, 0);
    cout << x << '\n';
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