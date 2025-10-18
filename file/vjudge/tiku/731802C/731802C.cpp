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
const ll MAXN = 1000050;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll v[1 << 23];
void solve()
{

    cin >> n;
    for (int i = 0; i < (1ll << 23); i++)
    {
        v[i] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        v[a[i] ^ ((1ll << 23) - 1)] = a[i];
    }
    // 多加一个1的答案肯定也适用于自己
    for (int i = (1ll << 23) - 1; i > 0; i--)
    {
        for (int j = 0; j < 23; j++)
        {
            if (v[i | (1ll << j)] == -1)
            {
                continue;
            }
            v[i] = v[i | (1ll << j)];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << v[a[i]] << ' ';
    }
    cout << '\n';
}
// .
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