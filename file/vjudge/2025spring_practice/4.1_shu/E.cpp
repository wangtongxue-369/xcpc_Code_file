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
    string s;
    cin >> s;
    ll u, v;
    vector<vector<ll>> ve(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        ve[i].push_back(u);
        ve[i].push_back(v);
    }
    ans = 1e18;
    function<void(ll x, ll c)> dfs = [&](ll x, ll c)
    {
        if (ve[x][0] == 0 && ve[x][1] == 0)
        {
            ans = min(ans, c);
            return;
        }
        ll minn = 1e18;
        if (ve[x][0] != 0)
        {
            ll p = 0;
            if (s[x - 1] != 'L')
            {
                p++;
            }
            dfs(ve[x][0], c + p);
        }
        if (ve[x][1] != 0)
        {
            ll p = 0;
            if (s[x - 1] != 'R')
            {
                p++;
            }
            dfs(ve[x][1], c + p);
        }
    };
    dfs(1, 0);
    cout << ans << '\n';
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