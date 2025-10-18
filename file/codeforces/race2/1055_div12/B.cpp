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
    cin >> n;
    ll rk, ck, rd, cd;
    cin >> rk >> ck >> rd >> cd;
    if (rk < rd && ck < cd)
    {
        cout << max(rd, cd);
    }
    else if (rk < rd && ck > cd)
    {
        cout << max(rd, n - cd);
    }
    else if (rk < rd && ck == cd)
    {
        cout << rd;
    }
    else if (rk > rd && ck < cd)
    {
        cout << max(n - rd, cd);
    }
    else if (rk > rd && ck > cd)
    {
        cout << max(n - rd, n - cd);
    }
    else if (rk > rd && ck == cd)
    {
        cout << n - rd;
    }
    else if (rk == rd && ck < cd)
    {
        cout << cd;
    }
    else if (rk == rd && ck > cd)
    {
        cout << n - cd;
    }
    cout << '\n';
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