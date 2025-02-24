#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x3f3f3f3f
const ll mod = 1e9 + 7;
const ll MAXN = 500005;
const ll base1 = 131;
const ll base2 = 127;
ll _ = 1, n, m, ans = 0, a[MAXN], f[MAXN];
ll sum = 0;
ll get(ll x)
{
    if (x == -1)
    {
        return 0;
    }
    ll in = x / n;
    ll i = x % n;
    ll res = in * sum;
    cout << "in " << x << '\n';
    cout << "?     " << i << ' ' << in << '\n';

    // if (i > n - in)
    // {
    //     res += a[n - 1] - a[max(0ll, in - 1)];
    //     cout << a[n - 1] << "! " << a[max(0ll, in - 1)] << '\n';
    //     cout << '!' << res << '\n';
    //     res += a[i - (n - 1 - in)];
    // }
    // else
    // {
    //     res += a[i + in] - a[in - 1];
    // }
    return res;
}

void solve()
{
    ll q;
    cin >> n >> q;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (i != 0)
        {
            a[i] += a[i - 1];
        }
    }
    ll l, r;
    while (q--)
    {
        cin >> l >> r;
        // l--, r--;
        cout << get(r) - get(l - 1) << '\n';
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
