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
ll _ = 1, n, m; // ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll d, ans = -1;
    cin >> n >> m >> d;
    vector<ll> a, b;
    ll x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x;
        b.push_back(x);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        ll r = min(a[i] + d, b[m - 1]);
        // cout << i << ' ' << r << '\n';
        ll it = lower_bound(b.begin(), b.end(), r) - b.begin();

        if (b[it] > r)
        {
            it--;
        }
        if (it < 0 || b[it] < a[i] - d)
        {
            continue;
        }
        // cout << i << ' ' << b[it] << '\n';
        ans = max(ans, a[i] + b[it]);
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
