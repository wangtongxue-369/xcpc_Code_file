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
    cin >> n;
    vector<vector<ll>> ve(n + 10);
    ll l, r;
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        if (l != 0)
        {
            ve[i].push_back(l);
        }
        if (r != 0)
        {
            ve[i].push_back(r);
        }
    }
    vector<ll> dep(n + 10);
    ans = 0;
    function<void(ll x, ll d)> dfs = [&](ll x, ll d)
    {
        dep[x] = d;
        ans = max(ans, d);
        for (auto it : ve[x])
        {
            dfs(it, d + 1);
        }
    };
    dfs(1, 1);
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