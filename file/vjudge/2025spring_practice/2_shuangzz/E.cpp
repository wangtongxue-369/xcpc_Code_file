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
ll _ = 1, n, m, ans = 0, a[MAXN], h[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    ll l, r;
    l = 1;
    ll sum = a[1];
    while (l <= n && a[l] > k)
    {
        l++;
    }
    sum = a[l];
    for (r = l; r <= n; r++)
    {
        if (r == n)
        {
            // cout << l << ' ' << r << '\n';
            ans = max(ans, r - l + 1);
            break;
        }
        // cout << h[r] << ' ' << h[r + 1] << endl;
        if (r != n && h[r] % h[r + 1] == 0)
        {
            if (sum + a[r + 1] <= k)
            {
                sum += a[r + 1];
                continue;
            }
            else
            {
                // cout << l << ' ' << r << '\n';
                ans = max(ans, r - l + 1);
                sum += a[r + 1];
                while (sum > k && l <= r)
                {
                    sum -= a[l];
                    l++;
                }
            }
        }
        else
        {
            // cout << l << ' ' << r << '\n';
            ans = max(ans, r - l + 1);
            while (r + 1 <= n && a[r + 1] > k)
            {
                r++;
            }
            sum = a[r + 1];
            l = r + 1;
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
