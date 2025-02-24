#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f
const ll mod = 1e9 + 7;
const ll MAXN = 1000005;
ll _ = 1, n, m, ans = 0; // a[MAXN], f[MAXN];
void solve()
{
    ll k;
    cin >> n >> k;
    n %= mod;
    if (k == 1)
    {
        cout << n << '\n';
        return;
    }
    // f[1] = 1;
    // f[2] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     f[i] = f[i - 1] + f[i - 2];
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    ll t = 2;

    ll a = 2, b = 1, c = 1;
    while (a != 0)
    {
        a = (b + c) % k;
        c = b;
        b = a;
        t++;
    }
    // for (ll i = 3;; i++)
    // {
    //     f[i] = (f[i - 1] + f[i - 2]) % k;
    //     // cout << f[i] << ' ';
    //     if (f[i] == 0)
    //     {
    //         t = i;
    //         break;
    //     }
    // }
    // cout << t << '\n';
    cout << (n * t) % mod << '\n';
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
