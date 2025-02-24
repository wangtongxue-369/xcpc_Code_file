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
ll _ = 1, n, m, ans = 0, a[MAXN], lastm[MAXN];
ll k;
void solve()
{
    cin >> n >> k;
    ll l = 0, r = 1e10;
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l = max(l, a[i]);
    }
    maxn = l;
    function<bool(ll x)> check = [&](ll x)
    {
        ll res = 0, sum = 0;
        ll p;
        for (int i = 1; i < n; i++)
        {
            p = x;
            sum = 0;
            if (a[i] >= x)
            {
                return 1;
            }
            sum += x - a[i];
            p--;
            p = max(p, 0ll);
            for (int j = i + 1; j <= n; j++)
            {

                if (a[j] >= p)
                {
                    break;
                }
                if (j == n)
                {
                    sum += k + 1;
                    break;
                }
                sum += p - a[j];
                p--;
                p = max(p, 0ll);
            }
            if (sum <= k)
            {
                return 1;
            }
        }
        return 0;
    };
    r = l + k;
    while (l < r)
    {
        ll mid = (l + r + 1) >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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
