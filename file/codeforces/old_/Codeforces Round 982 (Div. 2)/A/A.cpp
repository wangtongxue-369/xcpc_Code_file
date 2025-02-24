#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    cin >> n;
    ll w, h, maxnw = 0, maxnh = 0;
    map<ll, ll> ma;
    for (int i = 1; i <= n; i++)
    {
        cin >> w >> h;
        maxnw = max(maxnw, w);
        maxnh = max(maxnh, h);
        for (int i = 1; i <= w; i++)
        {
            ma[i] = max(ma[i], h);
        }
    }
    ans = 0;
    ans += maxnh + maxnw;
    for (int i = 1; i <= 100; i++)
    {
        if (ma[i] == 0)
        {
            break;
        }
        if (ma[i] == ma[i + 1])
        {
            ans += 1;
            continue;
        }
        else
        {
            ans += abs(ma[i + 1] - ma[i]) + 1;
            continue;
        }
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
