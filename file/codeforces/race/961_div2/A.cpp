#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    if (k == 0)
    {
        cout << 0 << '\n';
        return;
    }
    ans = 0;
    ans++;
    k -= n;
    if (k <= 0)
    {
        cout << ans << '\n';
        return;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        k -= i;
        ans++;
        if (k <= 0)
        {
            cout << ans << '\n';
            return;
        }
        k -= i;
        ans++;
        if (k <= 0)
        {
            cout << ans << '\n';
            return;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
