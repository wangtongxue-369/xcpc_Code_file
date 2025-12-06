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
    ll x, y, z;
    cin >> x >> y >> z;
    for (int i = 0; i <= 32; i++)
    {
        bool flag = 0;
        for (int a = 0; a <= 1; a++)
        {
            for (int b = 0; b <= 1; b++)
            {
                for (int c = 0; c <= 1; c++)
                {
                    if ((x & (1ll << i)) && ((a & b) == 1) || ((x & (1ll << i)) == 0) && ((a & b) == 0))
                    {
                        if ((y & (1ll << i)) && ((b & c) == 1) || ((y & (1ll << i)) == 0) && ((b & c) == 0))
                        {
                            if ((z & (1ll << i)) && ((a & c) == 1) || ((z & (1ll << i)) == 0) && ((a & c) == 0))
                            {
                                flag = 1;
                            }
                        }
                    }
                }
            }
        }
        if (flag == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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