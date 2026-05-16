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
#define ld long double
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
    map<ll, ll> mab, mbc, mac;
    map<PII, ll> ma;
    cin >> n;
    string s;
    cin >> s;
    ll zong = n * (n + 1) / 2;
    ll pa = 0, pb = 0, pc = 0;
    mab[0]++;
    mac[0]++;
    mbc[0]++;
    ma[{0, 0}]++;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'A')
        {
            pa++;
        }
        else if (s[i] == 'B')
        {
            pb++;
        }
        else
        {
            pc++;
        }
        mab[pa - pb]++;
        mac[pa - pc]++;
        mbc[pb - pc]++;
        ma[{pa - pb, pa - pc}]++;
    }
    ll sum = 0;
    for (auto [i, v] : mab)
    {
        sum += v * (v - 1) / 2;
    }
    for (auto [i, v] : mac)
    {
        sum += v * (v - 1) / 2;
    }
    for (auto [i, v] : mbc)
    {
        sum += v * (v - 1) / 2;
    }
    for (auto [i, v] : ma)
    {
        sum -= v * (v - 1) / 2;
        sum -= v * (v - 1) / 2;
    }

    cout << zong - sum << '\n';
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