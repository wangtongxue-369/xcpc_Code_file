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
ll _ = 1, n, m, ans = 0, c[MAXN]; // yj[MAXN];
void solve()
{
    ll y;
    cin >> n >> y;
    ll maxn = 0;
    vector<ll> yj(2e5 + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        maxn = max(maxn, c[i]);
        yj[c[i]]++;
    }
    vector<ll> pryj(2e5 + 10);
    for (int i = 1; i <= 2e5; i++)
    {
        pryj[i] = pryj[i - 1] + yj[i];
    }
    if (maxn == 1)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += c[i];
        }
        cout << sum << '\n';
        return;
    }
    ll ans = -1e18;
    for (ll x = 2; x <= maxn; x++)
    {
        ll sum = 0;
        ll pai = 0;

        for (ll v = 1; v * x <= maxn + x + 1000; v++)
        {
            ll l = (v - 1) * x + 1;
            ll r = min(v * x, maxn);
            // jiagequjian1
            if (l > maxn)
            {
                break;
            }
            ll cnt = pryj[r] - pryj[l - 1];
            sum += v * cnt;
            if (v <= maxn)
            {
                pai += min(cnt, yj[v]);
            }
        }
        ll p = sum - (n - pai) * y;
        ans = max(ans, p);
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
