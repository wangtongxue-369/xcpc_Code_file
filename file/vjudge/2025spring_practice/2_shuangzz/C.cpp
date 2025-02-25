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
    ll k, q;
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = 1, len;
    ans = 0;
    ll r;
    for (int l = 1; l <= n; l++)
    {
        if (a[l] <= q)
        {
            r = l;
            while (a[r] <= q && r <= n)
            {
                r++;
            }
            r--;
            // cout << l << ' ' << r << '\n';
            if ((r - l + 1) >= k)
            {
                len = r - l + 1;
                ans += ((len - k + 1) + 1) * (len - k + 1) / 2;
            }
            l = r;
            continue;
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
