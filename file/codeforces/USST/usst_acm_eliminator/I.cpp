#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    cin >> n >> m;
    vector<pair<ll, ll>> ve;
    ll a, c;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> c;
        ve.push_back({c, a});
    }
    sort(ve.begin(), ve.end());
    ll k = n;
    for (int i = 0; i < ve.size(); i++)
    {
        ll k1 = k;
        k = __gcd(k, ve[i].second);
        ans += (k1 - k) * ve[i].first;
    }
    if (k != 1)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cin>>_;
    while (_--)
    {
        solve();
    }
    return 0;
}
