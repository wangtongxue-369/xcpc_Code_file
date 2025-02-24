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
    ll br, bp, bs, dr, dp, ds;
    cin >> br >> bp >> bs;

    cin >> dr >> dp >> ds;
    ans = 0;
    if (br > 0)
    {
        if (dp > 0)
        {
            ll p = min(br, dp);
            ans += p;
            br -= p, dp -= p;
        }
        if (dr > 0)
        {
            ll p = min(br, dr);
            br -= p, dr -= p;
        }
        if (ds > 0)
        {
            ll p = min(br, ds);
            ans -= p;
            br -= p, ds -= p;
        }
    }
    if (bp > 0)
    {
        if (ds > 0)
        {
            ll p = min(bp, ds);
            ans += p;
            bp -= p, ds -= p;
        }
        if (dp > 0)
        {
            ll p = min(bp, dp);
            bp -= p, dp -= p;
        }
        if (dr > 0)
        {
            ll p = min(bp, dr);
            ans -= p;
            bp -= p, dr -= p;
        }
    }
    if (bs > 0)
    {
        if (dr > 0)
        {
            ll p = min(bs, dr);
            ans += p;
            bs -= p, dr -= p;
        }
        if (ds > 0)
        {
            ll p = min(bs, ds);
            bs -= p, ds -= p;
        }
        if (dp > 0)
        {
            ll p = min(bs, dp);
            ans -= p;
            bs -= p, dp -= p;
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
