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
    if (m == 1)
    {
        cout << 1 << '\n';
        return;
    }
    ll p = m, s = 1;
    ans = 1;
    ll c = abs(n - p);
    while (p <= n)
    {
        p *= m;
        s++;
        if (abs(n - p) < c)
        {
            ans = s;
            c = abs(n - p);
        }
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
