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
ll j[] = {0, 1, 3, 5, 7, 9};
ll o[] = {0, 0, 2, 4, 6, 8};
void solve()
{
    cin >> n;
    ll p = 0;
    for (ll i = 20; i >= 0; i--)
    {
        if (n >= f[i])
        {
            p = max(p, i);
            a[i] = n / f[i];
            n %= f[i];
        }
    }
    // for (int i = 0; i <= 20; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    a[1]++;
    p = max(p, (ll)1);
    for (ll i = 1; i <= 20; i++)
    {
        if (a[i] >= 5)
        {
            p = max(p, i + 1);
            a[i] = 0, a[i + 1]++;
        }
    }
    // for (int i = 0; i <= 20; i++)
    // {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    // cout << p << '\n';

    cout << a[p];
    ll pr = a[p];
    for (int i = p - 1; i >= 0; i--)
    {
        if (pr % 2 == 1)
        {
            cout << o[a[i]];
            pr = 0;
        }
        else
        {
            cout << j[a[i]];
            pr = 1;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i <= 20; i++)
    {
        f[i] = f[i - 1] * 5;
    }
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}