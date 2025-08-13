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
    ll x, y;
    // map<PII, vector<double>> ma;
    map<ll, ll> ma;
    vector<PII> ve;
    map<PII, ll> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        ve.push_back({x, y});
        s[{x, y}]++;
    }
    ll x1, x2, y1, y2;
    for (int i = 0; i < n; i++)
    {
        ma.clear();
        x1 = ve[i].first, y1 = ve[i].second;
        for (int j = 0; j < n; j++)
        {
            x2 = ve[j].first, y2 = ve[j].second;
            ll dis = (((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
            ans += ma[dis];
            ma[dis]++;
        }
        for (int j = 0; j < i; j++)
        {
            x2 = ve[j].first, y2 = ve[j].second;
            if ((x1 + x2) % 2 == 0 && (y1 + y2) % 2 == 0)
            {
                ans -= s[{(x1 + x2) / 2, (y1 + y2) / 2}];
            }
            // if (s.contains({2 * x1 - x2, 2 * y1 - y2}))
            // {
            //     ans -= s[{2 * x1 - x2, 2 * y1 - y2}];
            // }
        }
    }
    cout << ans << '\n';
}
// 枚举顶点 再找从顶点出发，长度相等的两个边
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