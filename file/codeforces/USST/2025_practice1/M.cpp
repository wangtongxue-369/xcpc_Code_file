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
ll _ = 1, n, m, ans = 0, a[MAXN], s[MAXN], t[MAXN]; // y[MAXN];
void solve()
{
    ll k, x, p;
    cin >> n >> k >> x >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> t[i];
    }
    vector<ll> ve;
    ll y;
    ve.push_back(p);
    for (int i = 1; i <= k; i++)
    {
        cin >> y;
        ve.push_back(y - t[i]);
    }
    sort(ve.begin(), ve.end());
    for (int i = 1; i <= n; i++)
    {
        ll t = ceil(1.0 * x / s[i]);
        // cout << "! " << i << ' ' << t << '\n';
        auto it = lower_bound(ve.begin(), ve.end(), t);
        // cout << *it << '\n';
        if (it != ve.end())
        {
            ans++;
        }
    }
    cout << ans << '\n';
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
