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
    cin >> n >> m;
    vector<ll> ve;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i];
        ve.push_back(a[i]);
    }
    ans = 0;
    sort(ve.begin(), ve.end());
    for (int k = 1; k < n; k++)
    {
        // 前k个是前面的
        // 后n-k个后面的
        // 找大于等于k和（n-k）的数量
        // ans+=k*(n-k);
        auto it1 = lower_bound(ve.begin(), ve.end(), k);
        auto it2 = lower_bound(ve.begin(), ve.end(), n - k);
        if (it1 == ve.end() || it2 == ve.end())
        {
            continue;
        }
        ll s1 = (m - (it1 - ve.begin()));
        ll s2 = (m - (it2 - ve.begin()));
        // cout << k << ' ' << (m - (it1 - ve.begin())) << ' ' << (m - (it2 - ve.begin())) << '\n';
        ans += (max(s1, s2) - 1) * min(s1, s2);
    }
    cout << ans << '\n';
}
// a1,a2;
// C
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
