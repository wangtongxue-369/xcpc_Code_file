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
    ll x, p;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            cin >> p;
            ve[i].push_back(p);
        }
    }
    vector<ll> ans(n + 10);
    function<void(ll x)> dfs = [&](ll x)
    {
        set<PII> se;
        vector<ll> v;
        v.push_back(x);
        ll px = x, pi = 0, nx = 0, ni = 0;
        while (!(nx == x && ni == 0))
        {
            // cout << "!  " << px << '\n';
            ll u = ve[px][pi], d = ve[u].size();
            for (int i = 0; i < ve[u].size(); i++)
            {
                if (ve[u][i] == px)
                {
                    nx = u;
                    ni = (i + 1) % ve[u].size();
                    break;
                }
            }
            PII e{min(px, u), max(px, u)};
            se.insert(e);
            if (!ni)
            {
                v.push_back(u);
            }
            px = nx, pi = ni;
        }
        for (auto it : v)
        {
            ans[it] = se.size();
        }
    };
    for (int i = 1; i <= n; i++)
    {
        if (!ans[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << '\n';
    }
    cout << '\n';
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