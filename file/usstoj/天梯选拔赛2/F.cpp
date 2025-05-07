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
    vector<ll> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c.push_back(i - 1 - a[i]);
    }
    sort(c.begin(), c.end());
    ll p = 0;
    if (c.size() % 2)
    {
        p = c[c.size() / 2];
    }
    else
    {
        p = (c[c.size() / 2 - 1] + c[c.size() / 2]) / 2;
    }
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(c[i] - p);
    }
    cout << ans << '\n';
}
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