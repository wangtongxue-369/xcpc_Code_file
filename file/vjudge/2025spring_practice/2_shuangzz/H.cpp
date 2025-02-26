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
        {
            return mint(1);
        }
        mint r = *this ^ (e / 2);
        r = r * r;
        return e & 1 ? *this * r : r;
    }
};

void solve()
{

    cin >> n >> m;
    vector<ll> a(n + 100, 0);
    map<ll, ll> ma;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[a[i]]++;
    }
    // 首先要把数量搞到m个，再判断是否满足小于等于m的需求
    vector<PII> ve;
    for (auto it : ma)
    {
        ve.push_back(it);
    }
    ll l = 0, r;
    n = ve.size();
    mint sum(1);
    mint ans(0);
    // ans = 0;
    for (r = 0; r < n; r++)
    {
        mint t(ve[r].second);
        sum = sum * ve[r].second;
        while (l < r && ve[r].first - ve[l].first + 1 > m)
        {
            sum = sum / ve[l].second;
            l++;
        }
        while (l < r && r - l + 1 > m)
        {
            sum = sum / ve[l].second;
            l++;
        }
        if (r - l + 1 == m)
        {
            ans = (ans + sum);
        }
    }
    cout << ans.x << '\n';
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
