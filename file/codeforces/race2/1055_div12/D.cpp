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
    vector<ll> v(n + 10, 0), v1(n + 10, 0), v2(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[i] = v[i - 1];
        v1[i] = v1[i - 1];
        v2[i] = v2[i - 1];
        v[i] += __lg(a[i]);
        if (((1ll << (__lg(a[i]))) + 1) == a[i])
        {
            v1[i]++;
        }
        if ((1ll << (__lg(a[i]))) == a[i])
        {
            v2[i]++;
        }
    }
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        ll sum = v[r] - v[l - 1];
        ll s1 = v1[r] - v1[l - 1]; // 整的+1的数量
        ll s2 = v2[r] - v2[l - 1]; // 整的的数量
        sum += (v1[r] - v1[l - 1]) / 2;
        sum += (r - l + 1) - s2 - s1;
        cout << sum << '\n';
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