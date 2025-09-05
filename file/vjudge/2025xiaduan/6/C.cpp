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
void solve()
{
    ll k;
    cin >> n >> k;
    set<ll> se;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        se.insert(a[i]);
    }
    sort(a + 1, a + 1 + k);
    if (k % 2 == 0)
    {
        ans = 0;
        for (int i = 2; i <= k; i += 2)
        {
            ans += a[i] - a[i - 1];
        }
        cout << ans << '\n';
        return;
    }
    ans = 1e18;
    vector<ll> q(k + 10), h(k + 10);
    for (int i = 1; i <= k; i++)
    {
        q[i] = q[i - 1];
        if (i % 2 == 0)
        {
            q[i] += a[i] - a[i - 1];
        }
    }
    for (int i = k; i >= 1; i--)
    {
        h[i] = h[i + 1];
        if ((k - i + 1) % 2 == 0)
        {
            h[i] += a[i + 1] - a[i];
        }
    }
    for (int i = 1; i <= k; i += 2)
    {
        ans = min(ans, q[i - 1] + h[i + 1]);
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