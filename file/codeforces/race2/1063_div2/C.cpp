/*
 /$$      /$$ /$$$$$$$$ /$$   /$$        /$$$$$$   /$$$$$$   /$$$$$$
| $$  /$ | $$|__  $__/| $$  / $$       /$__  $$ /$__  $$ /$__  $$
| $$ /$$$| $$   | $$   |  $$/ $$/      |__/  \ $$| $$  \__/| $$  \ $$
| $$/$$ $$ $$   | $$    \  $$$$/          /$$$$$/| $$$$$$$ |  $$$$$$$
| $$$_  $$$$    | $$     >$$  $$         |___  $$| $__  $$ \____  $$
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
ll _ = 1, n, m, ans = 0, a1[MAXN], a2[MAXN];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a1[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a2[i];
    }
    m = 2 * n;
    vector<ll> pmi1(n + 10), pma1(n + 10);
    vector<ll> hmi2(n + 10), hma2(n + 10);
    // vector<ll> pmi2(n + 10), pma2(n + 10);
    pmi1[0] = 1e18, pma1[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pmi1[i] = min(pmi1[i - 1], a1[i]);
        pma1[i] = max(pma1[i - 1], a1[i]);
    }
    hmi2[n + 1] = 1e18, hma2[n + 1] = 0;
    for (int i = n; i >= 1; i--)
    {
        hmi2[i] = min(hmi2[i + 1], a2[i]);
        hma2[i] = max(hma2[i + 1], a2[i]);
    }
    vector<PII> ve;
    // 分界点的最大最小
    for (int i = 1; i <= n; i++)
    {
        ve.push_back({min(pmi1[i], hmi2[i]), max(pma1[i], hma2[i])});
    }
    sort(ve.begin(), ve.end(), greater<>());
    ans = 0;
    ll p = 0;
    // 可行的r
    ll minnr = 2 * n + 1;
    for (ll i = 2 * n; i >= 1; i--)
    {
        while (p < n && ve[p].first >= i)
        {
            minnr = min(minnr, ve[p].second);
            p++;
        }
        if (p != 0)
        {
            ans += 2 * n - minnr + 1;
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