#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
#define PII pair<ll, ll>
const ll mod = 1e9 + 7;
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN], d[MAXN], s[MAXN], t[MAXN];
bool check(ll x)
{
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= x; i++)
    {
        f[s[i]] += d[i];
        f[t[i] + 1] -= d[i];
    }
    for (int i = 1; i <= n; i++)
    {
        f[i] += f[i - 1];
        if (f[i] > a[i])
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> d[i] >> s[i] >> t[i];
    }
    if (check(m))
    {
        cout << 0 << '\n';
        return;
    }
    ll l = 0, r = m;
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
    cout << -1 << '\n';
    cout << l + 1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
