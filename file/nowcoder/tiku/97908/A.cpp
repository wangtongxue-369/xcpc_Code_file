#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, k; // m, ans = 0, a[MAXN], f[MAXN];
ll a[MAXN], b[MAXN], c[MAXN], d[MAXN];

bool check(int t)
{
    for (int i = 1; i <= n; i++)
    {
        if (t < d[i])
            continue;

        if (k < c[i])
            return 1;
        int val = ((k - c[i]) + c[i] - 1) / c[i];

        int cnt = 0;
        for (int j = i + 1; j <= n; j++)
        {
            if (b[j] <= t)
            {
                cnt += a[j];
            }
        }
        if (cnt >= val)
            return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    ll l = 0, r = 4e18;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        // cout << mid << '\n';
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    if (l == 4e18)
    {
        cout << -1 << '\n';
        return;
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
