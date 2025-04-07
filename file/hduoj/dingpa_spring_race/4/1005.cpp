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
ll _ = 1, n, m; // t[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> m >> n >> k;
    ll t, p;
    vector<double> a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> p;
        if (t == 1)
        {
            a.push_back(p);
        }
        else
        {
            b.push_back(p / 10.0);
        }
    }
    sort(a.begin(), a.end(), greater());
    sort(b.begin(), b.end());
    ll n1 = a.size(), n2 = b.size();
    vector<double> prea, preb;
    prea.push_back(0);
    // prea.push_back(a[0]);
    for (int i = 0; i < n1; i++)
    {
        prea.push_back(prea[prea.size() - 1] + a[i]);
    }
    preb.push_back(1.0);
    // preb.push_back(b[0]);
    for (int i = 0; i < n2; i++)
    {
        preb.push_back(preb[preb.size() - 1] * b[i]);
    }
    ll s1, s2;
    double ans = 1e18;
    for (int i = 0; i <= k; i++)
    {
        double now = m;
        s1 = i;
        s2 = k - i;
        if (s1 > n1 || s2 > n2 || s2 < 0)
        {
            continue;
        }
        now = (m * preb[s2] - prea[i]);
        ans = min(ans, max(now, 0.0));
    }
    cout << fixed << setprecision(2) << ans << '\n';
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
