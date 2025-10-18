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
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
void solve()
{
    ll q;
    cin >> n >> q;
    vector<ll> pre1(n + 10, 0), pre0(n + 10, 0), v0(n + 10, 0), v1(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            pre1[i]++;
        }
        else
        {
            pre0[i]++;
        }
        if (a[i - 1] == 0 && a[i] == 0)
        {
            v0[i]++;
        }
        if (a[i - 1] == 1 && a[i] == 1)
        {
            v1[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        pre0[i] += pre0[i - 1];
        pre1[i] += pre1[i - 1];
        v0[i] += v0[i - 1];
        v1[i] += v1[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << v0[i] << ' ';
    }
    // cout << '\n';
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if ((pre0[r] - pre0[l - 1]) % 3 || (pre1[r] - pre1[l - 1]) % 3)
        {
            cout << -1 << '\n';
            continue;
        }
        ans = 0;
        ans = (pre0[r] - pre0[l - 1]) / 3 + (pre1[r] - pre1[l - 1]) / 3;
        if ((v0[r] - v0[l]) == 0 && (v1[r] - v1[l]) == 0)
        {
            ans++;
        }
        cout << ans << '\n';
    }
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