#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m;
ld sb[MAXN], xb[MAXN], a[MAXN];
const ld PI = acos(-1.0);
ld k;
ld ans;
ld check(ld x1)
{
    ld res = 0;
    for (int t = 0; t < n; t++)
    {
        ld s = sb[t] + x1 * cos(-2.0 * PI * k * t / (1.0 * n));
        ld x = xb[t] + x1 * sin(-2.0 * PI * k * t / (1.0 * n));
        res = max(res, sqrtl(s * s + x * x));
    }
    return res;
}
void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int t = 0; t < n; t++)
    {
        for (int s = 0; s < n; s++)
        {
            if (s == k)
            {
                continue;
            }
            sb[t] += a[s] * cos(-2.0 * PI * s * t / (1.0 * n));
            xb[t] += a[s] * sin(-2.0 * PI * s * t / (1.0 * n));
        }
    }
    ans = check(k);
    ll l = -1e9, r = 1e9;
    while (l <= r)
    {
        ll lm = l + (r - l) / 3, rm = r - (r - l) / 3;
        ans = min(ans, check(lm));
        ans = min(ans, check(rm));
        if (check(lm) < check(rm))
        {
            r = rm - 1;
        }
        else
        {
            l = lm + 1;
        }
    }
    cout << fixed << setprecision(13) << ans << "\n";
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
