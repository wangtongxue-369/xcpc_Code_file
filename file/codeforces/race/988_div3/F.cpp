#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 100005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, k; // a[MAXN], f[MAXN];

void solve()
{
    cin >> n >> m >> k;
    vector<ll> h(n + 100, 0);
    vector<ll> x(n + 100, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    function<bool(ll s)> check = [&](ll s)
    {
        ll hit = s * m;
        vector<PII> cf;
        for (int i = 1; i <= n; i++)
        {
            if (h[i] > hit)
            {
                continue;
            }
            else
            {
                int d = (h[i] + s - 1) / s;
                int l = x[i] - m + d;
                int r = x[i] + m - d;
                cf.emplace_back(l, 1);
                cf.emplace_back(r + 1, -1);
            }
        }
        sort(cf.begin(), cf.end());
        ll p = 0;
        for (auto it : cf)
        {
            p += it.second;
            if (p >= k)
            {
                return 1;
            }
        }
        return 0;
    };
    ll l = 1, r = 1000000001;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (r == 1000000001)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << l << '\n';
    }
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
