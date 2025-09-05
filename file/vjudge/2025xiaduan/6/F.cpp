/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$   | $$     >$$  $$         |___  $$| $__  $$ \____  $$
| $$$/ \  $$$   | $$    /$$/\  $$       /$$  \ $$| $$  \ $$ /$$  \ $$
| $$/   \  $$   | $$   | $$  \ $$      |  $$$$$$/|  $$$$$$/|  $$$$$$/
|__/     \__/   |__/   |__/  |__//$$$$$$\______/  \______/  \______/
                                |______/
*/
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
pair<ll, ll> get(char c)
{
    if (c == 'U')
        return {-1, 0};
    if (c == 'D')
        return {1, 0};
    if (c == 'L')
        return {0, -1};
    if (c == 'R')
        return {0, 1};
    return {0, 0};
}
void solve()
{
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll dx = x2 - x1;
    ll dy = y2 - y1;
    cin >> n;
    ll l;
    cin >> m >> l;
    vector<pair<char, ll>> sa(m + 10), sb(l + 10);
    for (int i = 1; i <= m; i++)
    {
        cin >> sa[i].first >> sa[i].second;
    }
    for (int i = 1; i <= l; i++)
    {
        cin >> sb[i].first >> sb[i].second;
    }
    ll i = 1, j = 1;
    ll ax = 0, ay = 0, bx = dx, by = dy;
    while (i <= m && j <= l)
    {
        // cerr << i << ' ' << j << '\n';
        ll p = min(sa[i].second, sb[j].second);
        // cerr << p << '\n';
        auto [dx1, dy1] = get(sa[i].first);
        auto [dx2, dy2] = get(sb[j].first);

        ll ddx = dx1 - dx2;
        ll ddy = dy1 - dy2;

        ll xc = bx - ax;
        ll yc = by - ay;
        if (ddx == 0 && ddy == 0)
        {
            if (ax == bx && ay == by)
            {
                ans += p;
            }
        }
        else if (ddx == 0)
        {
            if (ax == bx)
            {
                if (ddy != 0 && yc % ddy == 0)
                {
                    ll k = yc / ddy;
                    if (k >= 1 && k <= p)
                    {
                        ans++;
                    }
                }
            }
        }
        else if (ddy == 0)
        {
            if (ay == by)
            {
                if (ddx != 0 && xc % ddx == 0)
                {
                    ll k = xc / ddx;
                    if (k >= 1 && k <= p)
                    {
                        ans++;
                    }
                }
            }
        }
        else
        {
            if (xc % ddx == 0 && yc % ddy == 0)
            {
                ll k1 = xc / ddx;
                ll k2 = yc / ddy;
                if (k1 == k2 && k1 >= 1 && k1 <= p)
                {
                    ans++;
                }
            }
        }
        ax += p * dx1;
        ay += p * dy1;
        bx += p * dx2;
        by += p * dy2;
        sa[i].second -= p;
        sb[j].second -= p;
        if (sa[i].second <= 0)
        {
            i++;
        }
        if (sb[j].second <= 0)
        {
            j++;
        }
    }
    cout << ans << '\n';
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