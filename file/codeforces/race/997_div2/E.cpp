#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 998244353;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m; // a[MAXN], f[MAXN];
ll euclid(ll a, ll b, ll &x, ll &y)
{
    if (!b)
    {
        return x = 1, y = 0, a;
    }
    ll d = euclid(b, a % b, y, x);
    return y -= a / b * x, d;
}
struct mint
{
    ll x;
    mint(ll xx) : x(xx) { x = xx; }
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
        {
            return mint(1);
        }
        mint r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};
vector<mint> cat(MAXN + 100, 0);
// mint cat[MAXN];
void init()
{
    cat[0].x = 1;
    cat[1].x = 1;
    for (ll i = 1; i <= 400500; i++)
    {
        cat[i] = cat[i - 1] * mint(4 * i - 2);
        cat[i] = cat[i] / mint(i + 1);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i][0] >> a[i][1];
        a[i][0]--;
        a[i][1]--;
    }
    vector c(n, vector<int>());
    for (auto [x, y] : a)
    {
        if (x != y)
            c[x].push_back(y);
    }
    for (auto &t : c)
    {
        ranges::sort(t);
    }
    mint ans(1);
    auto proc = [&](this auto &&self, int l, int r) -> void
    {
        if (l == r)
            return;
        int cur = l;
        int cnt = 0;
        while (cur < r)
        {
            while (!c[cur].empty() && c[cur].back() > r)
                c[cur].pop_back();
            if (c[cur].empty())
            {
                cnt++;
                cur++;
            }
            else
            {
                int to = c[cur].back();
                c[cur].pop_back();
                self(cur, to);
                cur = to;
            }
        }
        ans = ans * cat[cnt];
    };
    proc(0, n - 1);
    cout << ans.x << endl;
    // cin >> n >> m;
    // ll x, y;
    // vector ve(n + 10, vector<ll>());
    // for (int i = 1; i <= m; i++)
    // {
    //     cin >> x >> y;
    //     x--;
    //     y--;
    //     if (x != y)
    //     {
    //         ve[x].push_back(y);
    //     }
    // }
    // for (auto it : ve)
    // {
    //     sort(it.begin(), it.end());
    // }
    // mint ans(1);
    // auto dfs = [&](this auto &&self, ll l, ll r) -> void
    // {
    //     if (l == r)
    //     {
    //         return;
    //     }
    //     ll p = l;
    //     ll cnt = 0;
    //     while (p < r)
    //     {
    //         while (!ve[p].empty() && ve[p].back() > r)
    //         {
    //             ve[p].pop_back();
    //         }
    //         if (ve[p].empty())
    //         {
    //             p++;
    //             cnt++;
    //         }
    //         else
    //         {
    //             ll to = ve[p].back();
    //             ve[p].pop_back();
    //             self(p, to);
    //             p = to;
    //         }
    //     }
    //     ans = ans * cat[cnt];
    // };
    // dfs(0, n - 1);
    // cout << ans.x << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    // for (int i = 10000; i <= 10500; i++)
    // {
    //     cout << cat[i].x << ' ';
    // }
    cin >> _;
    // cout << cat[2300] % mod << '\n';
    while (_--)
    {
        solve();
    }
    return 0;
}
