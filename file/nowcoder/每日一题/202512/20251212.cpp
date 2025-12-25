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
    string s;
    cin >> s;
    ll cntA = 0;
    ll cnta = 0;
    ll cnt0 = 0;
    ll cntc = 0;
    for (auto it : s)
    {
        if ('a' <= it && it <= 'z')
        {
            cnta++;
        }
        else if ('A' <= it && it <= 'Z')
        {
            cntA++;
        }
        else if ('0' <= it && it <= '9')
        {
            cnt0++;
        }
        else if (it == ',' || it == '.' || it == '?' || it == '!')
        {
            cntc++;
        }
    }
    ll ans = cntA == 1 ? 25 : cntA * 65;
    ans += cnta == 1 ? 25 : cnta * 65;
    ans += cnt0 == 1 ? 9 : cnt0 * 65;
    ans += cntc == 1 ? 3 : cntc * 65;
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