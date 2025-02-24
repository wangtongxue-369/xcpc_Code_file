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
ll _ = 1, n, m, ans = 0, w[MAXN], v[MAXN];
ll s;
ll l[MAXN], r[MAXN];
ll prew[MAXN];
ll pre[MAXN];
ll y;

bool check(ll x)
{
    memset(prew, 0, sizeof(prew));
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
    {
        if (w[i] >= x)
        {
            prew[i]++;
            pre[i] += v[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        prew[i] += prew[i - 1];
        pre[i] += pre[i - 1];
    }
    ll s1 = 0, s2 = 0;
    y = 0;
    for (int i = 1; i <= m; i++)
    {
        s1 = prew[r[i]] - prew[l[i] - 1];
        s2 = pre[r[i]] - pre[l[i] - 1];
        y += s1 * s2;
    }
    if (y > s)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void solve()
{
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> l[i] >> r[i];
    }
    ll l = 1, r = 1e10;
    ans = s;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            r = mid;
            ans = min(ans, llabs(s - y));
        }
        else
        {
            l = mid + 1;
            ans = min(ans, llabs(s - y));
        }
    }
    cout << ans << '\n';
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
