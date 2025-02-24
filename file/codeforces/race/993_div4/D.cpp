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
    map<ll, ll> ma;
    vector<ll> ve;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (ma.count(a[i]) == 0)
        {
            ve.push_back(a[i]);
        }
        ma[a[i]] = 1;
    }
    for (auto it : ve)
    {
        cout << it << ' ';
    }
    for (int i = 1; i <= n; i++)
    {
        if (ma.count(i) == 0)
        {
            cout << i << ' ';
        }
    }
    cout << '\n';
    // bool flag = 0;
    // ll p = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (ma.count(i) == 0)
    //     {
    //         p = i, flag = 1;
    //         break;
    //     }
    // }
    // if (flag == 0)
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         cout << a[i] << ' ';
    //     }
    //     cout << '\n';
    //     return;
    // }
    // else
    // {
    //     ma.clear();
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (ma.count(a[i]))
    //         {
    //             cout << p << ' ';
    //         }
    //         else
    //         {
    //             cout << a[i] << ' ';
    //             ma[a[i]] = 1;
    //         }
    //     }
    //     cout << '\n';
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
