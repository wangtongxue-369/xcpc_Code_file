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
    ll k;
    cin >> n >> k;
    vector<ll> ve;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i] / k;
        ve.push_back(k - a[i] % k);
    }
    sort(ve.begin(), ve.end());
    cin >> m;
    for (auto it : ve)
    {
        if (m >= it)
        {
            ans++;
            m -= it;
        }
    }
    ans += m / k;
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
