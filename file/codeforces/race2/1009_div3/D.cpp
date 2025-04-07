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
ll _ = 1, n, m, ans = 0, x[MAXN], r[MAXN];
void solve()
{
    cin >> n >> m;
    vector<vector<PII>> ve(m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i];
    }
    map<ll, ll> ma;
    // cout << (ll)sqrt(1.0 * 1 * 1 - 1.0 * 1 * 1) << '\n';
    for (int i = 1; i <= n; i++)
    {
        for (ll j = -r[i]; j <= r[i]; j++)
        {
            if (ma.contains(x[i] + j))
            {
                ma[x[i] + j] = max(ma[x[i] + j], 2 * (ll)sqrt(1.0 * r[i] * r[i] - 1.0 * abs(j) * abs(j)) + 1);
            }
            else
            {
                ma[x[i] + j] = 2 * (ll)sqrt(1.0 * r[i] * r[i] - 1.0 * abs(j) * abs(j)) + 1;
            }
            // cout << i << ' ' << j << ' ' << 2 * (ll)sqrt(1.0 * r[i] * r[i] - 1.0 * abs(j) * abs(j)) + 1 << '\n';
        }
    }
    ans = 0;
    for (auto it : ma)
    {
        ans += it.second;
    }
    cout << ans << '\n';
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
