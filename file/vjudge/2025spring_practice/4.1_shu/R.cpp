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
ll _ = 1, n, m, ans = 0, a[MAXN], ha[MAXN];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll u, v;
    vector<vector<ll>> ve(n + 10);
    for (ll i = 1; i <= n; i++)
    {
        cin >> u >> v;
        if (u != -1)
        {
            ve[i].push_back(u);
        }
        if (v != -1)
        {
            ve[i].push_back(v);
        }
    }
    function<ll(ll x, ll d)> dfs = [&](ll x, ll d)
    {
        ll res = 0;
        if (ve[x].size() == 2)
        {
        }
    };
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    ha[0] = base1;
    for (int i = 1; i <= n; i++)
    {
        ha[i] = ha[i - 1] * base1;
        ha[i] %= mod;
    }
    while (_--)
    {
        solve();
    }
    return 0;
}