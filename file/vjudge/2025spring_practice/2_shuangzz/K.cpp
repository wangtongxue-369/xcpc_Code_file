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
ll w, h;
ll f1(ll x, ll y)
{
    if (x == 0)
    {
        return y;
    }
    if (y == h)
    {
        return h + x;
    }
    if (x == w)
    {
        return h + w + (h - y);
    }
    if (y == 0)
    {
        return h + w + h + (w - x);
    }
}
pair<double, double> get(double t)
{
    pair<double, double> res;
    if (t <= h)
    {
        res.first = 0;
        res.second = t;
        return res;
    }
    if (t <= h + w)
    {
        res.first = t - 1.0 * h;
        res.second = h;
        return res;
    }
    if (t <= 2.0 * h + w)
    {
        res.first = w;
        res.second = 2.0 * h + w - t;
        return res;
    }
    res.first = 2.0 * (h + w) - t;
    res.second = 0;
    return res;
}
bool cmp(PII s1, PII s2)
{
    return s1.first < s2.first;
}
void solve()
{

    cin >> n >> w >> h;
    ll x1, y1, x2, y2;
    vector<PII> ve;
    map<ll, ll> ma;
    vector<bool> vis(n + 100, 0);
    for (ll i = 1; i <= n; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // ma[f1(x1, y1)]++;
        // ma[f1(x2, y2)]--;
        ve.emplace_back(f1(x1, y1), i);
        ve.emplace_back(f1(x2, y2), i);
    }
    sort(ve.begin(), ve.end(), cmp);
    ll l = 0, r = 0;
    ll len = ve.size();
    ll cnt = 0;
    for (int l = 0; l < ve.size(); l++)
    {

        while (vis[ve[r].second] == 0)
        {
            vis[ve[r].second] = 1;
            r++;
            r %= len;
            cnt++;
        }
        if (cnt == n)
        {
            pair<double, double> x = get(1.0 * ve[l].first - 0.5);
            // cout << 1 << '\n';
            printf("1\n");
            // cout << x.first << ' ' << x.second << ' ';
            printf("%.8lf %.8lf ", x.first, x.second);
            x = get(ve[r].first - 0.5);
            // cout << x.first << ' ' << x.second << ' ';
            printf("%.8lf %.8lf", x.first, x.second);
            return;
        }
        vis[ve[l].second] = 0;
        cnt--;
    }
    printf("2\n0.5 0 %.8f %.8f\n0 %.8f %.8f %.8f\n", w - 0.5, 1.0 * h, h - 0.5, 1.0 * w, 0.5);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
