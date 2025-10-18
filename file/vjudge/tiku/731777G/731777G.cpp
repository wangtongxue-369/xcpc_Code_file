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
ll lowbit(ll x)
{
    return x & (-x);
}
void add(ll x, ll v)
{
    while (x <= n)
    {
        f[x] += v;
        x += lowbit(x);
    }
}
void solve()
{
    ans = 0;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == '1')
        {
            if (i + lowbit(i) <= n)
                f[i + lowbit(i)]++;
        }
        if (s[i - 1] == '0')
        {
            if (f[i] == 1)
            {
                ans++;
            }
        }
        else // s 1
        {
            if (f[i] == 0)
            {
                ans++;
            }
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