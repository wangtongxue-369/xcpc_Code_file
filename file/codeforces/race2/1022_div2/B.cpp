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
    ll x;
    cin >> n >> x;
    vector<ll> ve;
    vector<ll> an(40);
    ll c = __builtin_popcountll(x);
    if (n <= c)
    {
        cout << x << '\n';
        return;
    }
    if ((n - c) % 2 == 0)
    {
        cout << x + (n - c) << '\n';
        return;
    }
    if (n == 1 && x == 0)
    {
        cout << -1 << '\n';
        return;
    }
    if (n % 2 == 1)
    {
        if (x == 1)
        {
            cout << n << '\n';
            return;
        }
        if (x == 0)
        {
            cout << n + 3 << '\n';
            return;
        }
        if (x > 1)
        {
            cout << x + n - c + 1 << '\n';
            return;
        }
    }
    else
    {
        if (x == 0)
        {
            cout << n << '\n';
            return;
        }
        if (x == 1)
        {
            cout << n + 3 << '\n';
            return;
        }
        if (x > 1)
        {
            cout << x + n - c + 1 << '\n';
            return;
        }
    }
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