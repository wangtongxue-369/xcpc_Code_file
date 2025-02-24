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
    ll d;
    cin >> n >> d;
    vector<ll> v;
    v.push_back(1);
    if (d % 3 == 0 || n >= 3)
    {
        v.push_back(3);
    }
    if (d == 5)
    {
        v.push_back(5);
    }
    if (d == 7 || n >= 3)
    {
        v.push_back(7);
    }
    if (d == 9 || (n >= 6) || (d % 3 == 0 && n >= 3))
    {
        v.push_back(9);
    }
    for (auto it : v)
    {
        cout << it << ' ';
    }
    cout << '\n';

    // for (int i = 1; i <= 9; i++)
    // {
    //     ll x = i;
    //     ll p = 15;
    //     while (p--)
    //     {
    //         cout << x << '\n';
    //         for (int j = 1; j <= 9; j += 2)
    //         {
    //             if (x % j == 0)
    //             {
    //                 cout << j << ' ';
    //             }
    //         }
    //         cout << '\n';
    //         x *= 10;
    //         x += i;
    //     }
    // }
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
