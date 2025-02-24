#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN];
ll d[MAXN];

vector<vector<ll>> ve(MAXN + 100);
const ll mod = 998244353;
ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}
struct mint
{
    ll x;
    mint(ll xx) : x(xx) {}
    mint operator+(mint b) { return mint((x + b.x) % mod); }
    mint operator-(mint b) { return mint((x - b.x + mod) % mod); }
    mint operator*(mint b) { return mint((x * b.x) % mod); }
    mint operator/(mint b) { return *this * invert(b); }
    mint invert(mint a)
    {
        ll x, y, g = euclid(a.x, mod, x, y);
        assert(g == 1);
        return mint((x + mod) % mod);
    }
    mint operator^(ll e)
    {
        if (!e)
            return mint(1);
        mint r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};
vector<mint> f(MAXN + 100, 0);
ll dfs(ll i, ll fa)
{
    ll res = 1e18;
    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        ll df = dfs(it, i);

        res = min(res, df);
    }
    if (res == 1e18)
    {
        d[i] = 0;
        return 1;
    }
    else
    {
        d[i] = res;
        return res + 1;
    }
}
void dfs2(ll i, ll fa)
{
    if (i == 1)
    {
        f[i].x = 1;
    }
    else
    {
        mint t = f[fa] * mint(d[i]) / (d[i] + 1);
        // cout << t.x << '\n';
        f[i].x = t.x;
    }
    for (auto it : ve[i])
    {
        if (it == fa)
        {
            continue;
        }
        dfs2(it, i);
    }
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ve[i].clear();
    }
    ll u, v;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    f[1].x = 1, f[0].x = 1;
    ll d1 = dfs(1, -1);
    dfs2(1, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << d[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        cout << f[i].x << ' ';
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
