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
    if (n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    if (n == 2 || n == 3 || n == 4)
    {
        cout << 2 << '\n';
        return;
    }
    ans = 2;
    ll s = 4;
    while (s < n)
    {
        ans++;
        s = (s + 1) * 2;
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
