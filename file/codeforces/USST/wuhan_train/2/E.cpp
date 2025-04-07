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
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ans = 2e18;
    ll k, a, b;
    cin >> n >> k >> m >> a >> b;
    ll p = 0, sum = 0;
    if (n % m == 0)
    {
        cout << 0 << '\n';
        return;
    }
    if (k == 1)
    {
        cout << -1 << '\n';
        return;
    }
    while (n)
    {
        sum = p;
        __int128_t l = n, r = n;
        while (l / m == r / m && l % m != 0)
        {
            l = l * k;
            r = r * k + (k - 1);
            sum += a;
            if (sum >= ans)
            {
                break;
            }
        }
        ans = min(ans, sum);
        n /= k;
        p += b;
    }
    ans = min(ans, p);
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
