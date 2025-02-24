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
ll _ = 1, n, m, ans = 0, l[MAXN], r[MAXN];
void solve()
{
    cin >> n >> m;
    ll left = 0, right = 1e9;
    vector<ll> a(m + 10, m + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        a[l[i]] = min(a[l[i]], r[i]);
    }
    for (int i = m - 1; i >= 1; i--)
    {
        a[i] = min(a[i], a[i + 1]);
    }
    for (int i = m; i >= 1; i--)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
    for (int i = 1; i <= m; i++)
    {
        ans += a[i] - i;
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
// 1 4 6 8 5 6 7
