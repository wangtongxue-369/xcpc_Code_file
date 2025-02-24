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
ll _ = 1, n, m, ans = 0, a[MAXN], b[MAXN];
bool check(ll k)
{
    ll x = 0, y = 1e9;
    for (int i = 1; i <= n; i++)
    {
        ll sl = a[i] - k * b[i];
        ll sr = k * b[i] + a[i];
        if (i == 1)
        {
            x = sl;
            y = sr;
            continue;
        }
        else
        {
            if (x > sr || y < sl)
            {
                return 0;
            }
            x = max(x, sl);
            y = min(y, sr);
        }
    }
    return x <= y;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll l = 0, r = 1e9;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
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
